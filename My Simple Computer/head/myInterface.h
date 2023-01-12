#ifndef INTERFACE_H
#define INTERFACE_H
#include "myBigChar.h"
#include "mySimpleComputer.h"
#include <ctype.h>
#include <string.h>
#include <unistd.h>
extern int instruction_counter;
int drawingBigChars ();
int ui_initial ();
int ui_update ();
int ui_setValue ();
int drawingBoxes ();

int drawing_texts ();
int ui_Counter ();
int drawing_memory ();
int drawing_flags ();
int drawing_IC ();
int ui_Accum ();
int drawing_Accum ();
int ui_setValue ();
bool checkCorrectInput (const char buffer[10]);
int ui_messageOutput (char *str, enum colors color);
int clearBuffIn ();
int ui_savefile ();
int ui_loadfile ();
#endif
