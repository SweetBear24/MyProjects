#include "myCU.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "myALU.h"
  
extern int accumulator;
extern int instruction_counter;

int READ (int operand){
  char buff[32];
  mt_gotoXY (30,1);
  sprintf (buff, "Input value: ");
  write (STDOUT_FILENO, buff, 14);
  char buffAf[32];
  scanf("%s", buffAf);
  sc_memorySet (operand, atoi (buffAf));

  return 0;
}

int WRITE (int operand){
  int value;
  int command;
  char buf[20];

  if (sc_memoryGet (operand, &value)
      || sc_commandDecode (value & 0x3FFF, &command, &operand))
    {
      sc_regSet (4, 1);
      return -1;
    }

  snprintf (buf, 20, "Output:> %c%02X%02X", (value & 0x4000) ? '-' : '+',
            command, operand);

  mt_gotoXY (1, 26);
  write (1, buf, 15);

  return 0;
}

int LOAD (int operand){
  int value = 0;
  sc_memoryGet (operand, &value);
  accumulator = value;
  return 0;
}

int STORE (int operand)
{
  sc_memorySet (operand, accumulator);
  return 0;
}

int
JUMP (int operand)
{
  instruction_counter = operand;
  CU ();
  return 0;
}

int JNEG (int operand)
{
  if (accumulator < 0)
    {
      instruction_counter = operand;
      CU ();
    }
  return 0;
}

int JZ (int operand)
{
  if (accumulator == 0)
    {
      instruction_counter = operand;
      CU ();
    }
  return 0;
}

int
MOVR (int operand)
{
  int value;
  sc_memoryGet (accumulator, &value);
  sc_memorySet (operand, value);
  return 0;
}
int
HALT ()
{
  sc_regSet (3, 1);
  instruction_counter = 0;

  return 0;
}

int
JNS (int operand)
{
  if (accumulator > 0)
    {
      instruction_counter = operand;
    }
  return 0;
}

int
JC (int operand)
{
  int tmp;
  sc_memoryGet (operand, &tmp);
  if (accumulator + tmp > 32767)
    {
      instruction_counter = operand;
    }
  return 0;
}

int
JNC (int operand)
{
  int tmp;
  sc_memoryGet (operand, &tmp);
  if (accumulator + tmp <= 32767)
    {
      instruction_counter = operand;
    }
  return 0;
}

int
JP (int operand)
{
  int val;
  sc_memoryGet (operand - 1, &val);
  if (val % 2 == 0)
    instruction_counter = operand;
  return 0;
}

int
JNP (int operand)
{
  int val;
  sc_memoryGet (operand - 1, &val);
  if (val % 2 != 0)
    instruction_counter = operand;
  return 0;
}

int
MOVA (int operand)
{
  int val;
  sc_memoryGet (operand, &val);
  sc_memorySet (accumulator, val);
  return 0;
}

int
MOVCA (int operand)
{
  int val, val2;
  sc_memoryGet (operand, &val);
  sc_memoryGet (accumulator, &val2);
  sc_memorySet (val2, val);
  return 0;
}

int
MOVCR (int operand)
{
  int val, val2;
  sc_memoryGet (accumulator, &val);
  sc_memoryGet (val, &val2);
  sc_memorySet (operand, val2);
  return 0;
}

int
CU ()
{
  int value = 0;
  sc_memoryGet (instruction_counter, &value);
  int command, operand;
  if (sc_commandDecode (value & 0x3FFF, &command, &operand))
    {
      sc_regSet (4, 1);
      return -1;
    }
  if (command == 0x66)
    command = 0x76;
  else if (command == 0x65)
    command = 0x75;
  if (((command >= 0x30) && (command <= 0x33))
      || ((command >= 0x51) && (command <= 0x54))
      || ((command >= 0x60) && (command <= 0x70)) || (command == 0x76)
      || (command == 0x75))
    {
      ALU (command, operand);
    }
  else
    {
      switch (command)
        {
        case 0x10:
          READ (operand);
          break;
        case 0x11:
          WRITE (operand);
          break;
        case 0x20:
          LOAD (operand);
          break;
        case 0x21:
          STORE (operand);
          break;
        case 0x40:
          JUMP (operand);
          break;
        case 0x41:
          JNEG (operand);
          break;
        case 0x42:
          JZ (operand);
          break;
        case 0x43:
          HALT ();
          break;
        case 0x55:
          JNS (operand);
          break;
        case 0x56:
          JC (operand);
          break;
        case 0x57:
          JNC (operand);
          break;
        case 0x58:
          JP (operand);
          break;
        case 0x59:
          JNP (operand);
          break;
        case 0x71:
          MOVA (operand);
          break;
        case 0x72:
          MOVR (operand);
          break;
        case 0x73:
          MOVCA (operand);
          break;
        case 0x74:
          MOVCR (operand);
          break;
        }
    }
  return 0;
}
