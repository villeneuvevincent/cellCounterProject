#ifndef _picture_h
#define _picture_h

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


typedef struct{
  int lignes;
  int colonnes;
  int max;
  unsigned char** pixels; //On va de O à 255
} IMAGE;

void libre(IMAGE im);
unsigned char** allocation(int l, int c);
IMAGE picture(char* file);
void ecriture(IMAGE im, char* copie);
IMAGE copie(IMAGE im);

#endif
