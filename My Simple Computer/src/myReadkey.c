#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "LB2.h"
#include "mySimpleComputer.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "keys.h"
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

static struct termios orig_termios;

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint)
{
  struct termios new_termios;
  if (tcgetattr(STDIN_FILENO, &new_termios) == -1)
  {
    return -1;
  }

  if (regime == 1)
  {                                // канонический режим
    new_termios.c_lflag |= ICANON; // включить канонический режим
    new_termios.c_lflag |= ECHO;
    new_termios.c_cc[VMIN] = vmin;   // минимальное количество символов для чтения
    new_termios.c_cc[VTIME] = vtime; // таймаут чтения в десятых секунды
  }
  else if (regime == 0) 
  {                                  // неканонический режим
    new_termios.c_lflag &= ~ICANON;  // выключить канонический режим
    new_termios.c_cc[VMIN] = vmin;   // минимальное количество символов для чтения
    new_termios.c_cc[VTIME] = vtime; // таймаут чтения в десятых секунды

    if (echo == 1)
    {
      new_termios.c_lflag |= ECHO; // включить вывод символов на экран
    }
    else if (echo == 0)
    {
      new_termios.c_lflag &= ~ECHO; // выключить вывод символов на экран
    }

    if (sigint == 1)
    {
      new_termios.c_lflag |= ISIG; // обработка символа прерывания (Ctrl+C)
    }
    else if (sigint == 0)
    {
      new_termios.c_lflag &= ~ISIG; // игнорирование символа прерывания (Ctrl+C)
    }
  }
  else
  {
    return -1; // неверный режим
  }

  if (tcsetattr(STDIN_FILENO, TCSANOW, &new_termios) == -1)
  {
    return -1;
  }
  
  return 0;
}
int rk_readkey(enum keys *key)
{
  char bf[6] = {0};
  if (read(STDIN_FILENO, bf, 6) == -1)
    return EXIT_FAILURE;

  if (!strncmp("\e[15~", bf, 5))
  {
    *key = KEY_F5;
  }
  else if (!strncmp("\e[17~", bf, 5))
  {
    *key = KEY_F6;
  }
  else if (!strncmp("\e[A", bf, 3))
  {
    *key = KEY_UP;
  }
  else if (!strncmp("\e[B", bf, 3))
  {
    *key = KEY_DOWN;
  }
  else if (!strncmp("\e[D", bf, 3))
  {
    *key = KEY_LEFT;
  }
  else if (!strncmp("\e[C", bf, 3))
  {
    *key = KEY_RIGHT;
  }
  else if (!strncmp("\n", bf, 1))
  {
    *key = KEY_ENTER;
  }
  else if (!strncmp("l", bf, 1))
  {
    *key = KEY_L;
  }
  else if (!strncmp("s", bf, 1))
  {
    *key = KEY_S;
  }
  else if (!strncmp("r", bf, 1))
  {
    *key = KEY_R;
  }
  else if (!strncmp("t", bf, 1))
  {
    *key = KEY_T;
  }
  else if (!strncmp("i", bf, 1))
  {
    *key = KEY_I;
  }
  else if (!strncmp("L", bf, 1))
  {
    *key = KEY_L;
  }
  else if (!strncmp("S", bf, 1))
  {
    *key = KEY_S;
  }
  else if (!strncmp("R", bf, 1))
  {
    *key = KEY_R;
  }
  else if (!strncmp("T", bf, 1))
  {
    *key = KEY_T;
  }
  else if (!strncmp("I", bf, 1))
  {
    *key = KEY_I;
  }else if (!strncmp("\e", bf, 1))
  {
    *key = KEY_ESC; 
  }

  else
  {
    write(STDOUT_FILENO, "Нажмите клавишу", 30);
    *key = KEY_UNKNOWN;
    return -1;
  }
  return EXIT_SUCCESS;
}

int rk_mytermsave(void)
{
  if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)
  {
    return -1;
  }
  return 0;
}

int rk_mytermrestore(void)
{
  if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios) == -1)
  {
    return -1;
  }
  return 0;
}

