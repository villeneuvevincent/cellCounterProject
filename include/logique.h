#ifndef _logique_h
#define _logique_h

#include "picture.h"

void erosion(IMAGE im);
void dilatation(IMAGE im);
void booleen(IMAGE im1, IMAGE im2, IMAGE sortie, int operation);
void erosion_m(IMAGE im, int seuil);
IMAGE erosion_u(IMAGE im);

#endif
