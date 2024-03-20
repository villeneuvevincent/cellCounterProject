#ifndef _reconstruction_h
#define _reconstruction_h

#include "picture.h"
IMAGE r_morphologique(IMAGE im, IMAGE gr);
void cadre(IMAGE im);
IMAGE supp_bord(IMAGE im);
void inversion(IMAGE im);
IMAGE boucher_trou(IMAGE im);

#endif
