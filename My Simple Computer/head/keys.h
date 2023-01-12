#pragma once

enum keys
{
  KEY_UNKNOWN,
  KEY_F5,
  KEY_F6,
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_ENTER,
  KEY_L,
  KEY_S,
  KEY_R,
  KEY_T,
  KEY_I,
  KEY_ESC,
};
int rk_mytermsave (void);
int rk_mytermrestore (void);
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readkey (enum keys *key);
 
