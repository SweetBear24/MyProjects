#include "myALU.h"
#include <math.h>

extern int accumulator;
char *
itoa (int value, char *result, int base)
{
  // check that the base if valid
  if (base < 2 || base > 36)
    {
      *result = '\0';
      return result;
    }

  char *ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do
    {
      tmp_value = value;
      value /= base;
      *ptr++
          = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrst"
            "uvwxyz"[35 + (tmp_value - value * base)];
    }
  while (value);

  // Apply negative sign
  if (tmp_value < 0)
    *ptr++ = '-';
  *ptr-- = '\0';
  while (ptr1 < ptr)
    {
      tmp_char = *ptr;
      *ptr-- = *ptr1;
      *ptr1++ = tmp_char;
    }
  return result;
}

char *
invert (char *str)
{
  for (int i = 0; i < strlen (str) - 1; i++)
    {
      if (str[i] == '1')
        {
          str[i] = '0';
        }
    }
  return str;
}

int
to_dec (char *str, int numeral_system)
{
  int ind = 0;
  int tmp = 0;
  for (int i = strlen (str); i >= 0; i--, ind++)
    {
      if (str[i] == '0')
        continue;
      tmp += pow (numeral_system, ind) * (str[i] & 0x0F);
    }
  return tmp;
}

int
NEG (int value)
{
  int x = value;               // исходное число
  int bits = sizeof (int) * 8; // количество бит в int
  int mask = 1 << (bits - 1); // маска для определения знакового бита
  int i, digit, carry, complement;

  if (x < 0)
    {
      x = -x;            // меняем знак числа
      complement = mask; // устанавливаем знаковый бит в 1
    }
  for (i = 0; i < bits - 1; i++)
    {
      digit = x & mask; // извлекаем i-й бит числа
      carry = ((complement & mask) | digit) >> (bits - 1); // вычисляем перенос
      complement = (complement << 1)
                   | digit; // сдвигаем число влево и добавляем i-й бит
      x = x << 1; // сдвигаем исходное число влево
      complement = complement + carry; // добавляем перенос
    }
  return complement;
}

int
ALU (int command, int operand)
{
  int tmp;
  sc_memoryGet (operand, &tmp);
  switch (command)
    {
    case 0x30: //сложение, результат в акк
      accumulator += tmp;
      break;
    case 0x31: //вычитание
      accumulator -= tmp;
      break;
    case 0x32: //деление
      if (tmp == 0)
        {
          sc_regSet (1, 1);
          return -1;
        }
      sc_regSet (1, 0);
      accumulator /= tmp;
      break;

    case 0x33: //произведение
      accumulator *= tmp;
      break;

    case 0x51:
      {
        char str[256];
        itoa (accumulator, str, 2);
        sc_memorySet (tmp, to_dec (invert (str), 2));
        break;
      }

    case 0x52: //логич и
      accumulator &= tmp;
      break;
    case 0x53: //логич или
      {
        accumulator |= tmp;
        break;
      }
    case 0x54: // xor
      {
        accumulator ^= tmp;
        break;
      }

    case 0x60:
      {
        accumulator = tmp << 1;
        break;
      }
    case 0x61:
      {
        accumulator = tmp >> 1;
        break;
      }
    case 0x62:
      {
        accumulator = (tmp << 1) | (tmp >> (sizeof (tmp) * 8 - 1));
      }

    case 0x63:
      {
        accumulator = (tmp >> 1) | (tmp << (sizeof (tmp) * 8 - 1));
      }

    case 0x64:
      {
        accumulator = NEG (tmp);
      }

    case 0x67:
      {
        accumulator = tmp << accumulator;
      }

    case 0x68:
      {
        accumulator = tmp >> accumulator;
      }

    case 0x69:
      {
        accumulator
            = (tmp << accumulator) | (tmp >> (sizeof (tmp) * 8 - accumulator));
      }

    case 0x70:
      {
        accumulator
            = (tmp >> accumulator) | (tmp << (sizeof (tmp) * 8 - accumulator));
      }

    case 0x75:
      {
        if (accumulator > 99 || accumulator < 0)
          {
            sc_regSet (2, 1);
            break;
          }
        int val;
        sc_memoryGet (accumulator, &val);
        accumulator = tmp + val;
        break;
      }

    case 0x76:
      {
        if (accumulator > 99 || accumulator < 0)
          {
            sc_regSet (2, 1);
            break;
          }
        int val;
        sc_memoryGet (accumulator, &val);
        accumulator = tmp - val;
        break;
      }
    }

  return 0;
}
