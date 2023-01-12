#include "mySignal.h"
#include "myInterface.h"
extern int accumulator;
extern int instruction_counter;
extern int currMemCell; 
void
ms_setSignals ()
{
  signal (SIGALRM, ms_timerHandler);
  signal (SIGUSR1, ms_userSignal);
}

void
ms_timerHandler (int sig)
{
  for (int i = 0; i < 5; i++)
    {
      int check;
      sc_regGet (i, &check);
      if (check)
        {
          sc_regSet (3, 1);
          return;
        }
    }

  CU ();
  int value;
  sc_regGet (3, &value);
  if (!value && instruction_counter <= 99)
    {
      instruction_counter++;
      ualarm (100000, 0);
    }
  else if (instruction_counter > 99)
    {
      instruction_counter = 0;
      sc_regSet (0, 0);
    }

  drawing_IC ();
  currMemCell = instruction_counter;
  ui_update ();
}

void
ms_userSignal (int sig)
{
  alarm (0);
  sc_regInit ();
  sc_regSet (3, 1);
  instruction_counter = 0;
  accumulator = 0;
  drawing_IC ();
}
