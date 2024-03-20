#include "picture.h"

void s_manuel(IMAGE p,unsigned char s){
      int j;

      for (j = 0; j < p.colonnes*p.lignes; j++) {

        if (p.pixels[0][j] > s) {
            p.pixels[0][j] = 255;

          }
          else {p.pixels[0][j] = 0;}
        }
      
}


unsigned char* histogramme(IMAGE p){

  //Création de l'Histogramme
  int j,i;
  unsigned char* tab;
  tab = (unsigned char*)calloc(256,sizeof(*tab));
  for ( j = 0; j < p.lignes*p.colonnes ; j++) {
    for (i = 0; i < 256; i++) {
      if (p.pixels[0][j] == i) {
        tab[i] += 1;
      }
    }

  }
  return tab;}


unsigned char Otsu(unsigned char* tab){

  //On fixe le seuil
  int s;
  double w0, w1, u0, u1, v, v0 = 0;
  unsigned char seuil;

  for (s = 1; s < 256; s++) {
  //DEFINITIONS

  //Probabilités de classes
  int i;
  w0 = 0; w1 = 0;
  for ( i = 0; i < s ; i++) {
    w0 += tab[i];
  }
  for ( i = s; i < 256 ; i++) {
    w1 += tab[i];
  }

  //Moyennes empiriques
  u0 = 0; u1 = 0;
  for ( i = 0; i < s ; i++) {
    u0 += i*tab[i];
  }
  for ( i = s; i < 256 ; i++) {
    u1 += i*tab[i];
  }

  if (w0 == 0 || w1 == 0 ) {u0 = 0; u1 = 0;}
  else {u0 = u0/w0;  u1 = u1/w1;}


  //variance inter-classe
  v = 0;
  v = w0*w1*(u0-u1)*(u0-u1);
  if (v0<=v) {
    v0 = v;
    seuil = s;
  }
}

  return seuil;

}
