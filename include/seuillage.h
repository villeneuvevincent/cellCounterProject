#ifndef _seuillage_h
#define _seuillage_h

#include "picture.h"
void s_manuel(IMAGE im, unsigned char s);
unsigned char* histogramme(IMAGE p);
unsigned char Otsu(unsigned char* tab);

#endif
