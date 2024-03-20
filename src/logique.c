#include "picture.h"
#include "reconstruction_m.h"

void erosion(IMAGE im){
  IMAGE e;
  e = copie(im);

int i,j ;
for (i = 1; i < im.lignes -1   ; i++) {
  for ( j = 1; j < im.colonnes - 1; j++) {
    if (e.pixels[i-1][j-1] == 0 || e.pixels[i-1][j] ==0 || e.pixels[i-1][j+1] ==0 ||  e.pixels[i][j - 1] ==0 || e.pixels[i][j] == 0 || e.pixels[i][j+1] ==0 ||  e.pixels[i+1][j-1] ==0 ||  e.pixels[i+1][j] ==0 ||  e.pixels[i+1][j+1] ==0 ){
      im.pixels[i][j] = 0;
    }
    else{im.pixels[i][j] = 255;}
  }

}
libre(e);
}

void dilatation(IMAGE im){
  IMAGE d;
  d = copie(im);

int i,j ;
for (i = 1; i < im.lignes -1 ; i++) {
  for ( j = 1; j < im.colonnes -1 ; j++) {
    if (d.pixels[i-1][j-1] == 255 || d.pixels[i-1][j] == 255 || d.pixels[i-1][j+1] == 255 ||  d.pixels[i][j - 1] == 255 || d.pixels[i][j] ==255 ||  d.pixels[i][j+1] == 255 ||  d.pixels[i+1][j-1] == 255 ||  d.pixels[i+1][j] == 255 ||  d.pixels[i+1][j+1] == 255 ){
      im.pixels[i][j] = 255;
    }
    else{im.pixels[i][j] = 0;}
  }

}
libre(d);
}

void booleen(IMAGE im1, IMAGE im2, IMAGE sortie, int operation){

  int i,j;
  for (i = 0; i < im1.lignes ; i++) {
    for ( j = 0; j < im1.colonnes ; j++) {
        switch(operation){
            case 0: //intersection
                if(im1.pixels[i][j] == 255 && im2.pixels[i][j] == 255){
                  sortie.pixels[i][j] = 255;
                }
                else{sortie.pixels[i][j] = 0;}

            break;

            case 1: //union
                if(im1.pixels[i][j] == 0 && im2.pixels[i][j] == 0){
                  sortie.pixels[i][j] = 0;
                }
                else{sortie.pixels[i][j] = 255;}

            break;

            case 2: //xor
                if((im1.pixels[i][j] == 255 && im2.pixels[i][j] == 255) || (im1.pixels[i][j] == 0 && im2.pixels[i][j] == 0)){
                  sortie.pixels[i][j] = 0;
                }
                else{sortie.pixels[i][j] = 255;}

            break;
      }
    }
  }
}

void erosion_m(IMAGE im, int seuil){
  int i = 0;
  do{
    erosion(im);
    i += 1;
  }while (i < seuil);
}

IMAGE erosion_u(IMAGE im){
  int j;
  IMAGE vide; vide = copie(im);
  for (j = 0; j < im.lignes*im.colonnes; j++){vide.pixels[0][j] = 0;}

  IMAGE erodes_ultimes = copie(vide), erodee = copie(vide), residus = copie(vide), reconstruite = copie(vide);
  IMAGE courante = copie(im);



  do{
    erodee = copie(courante);
    erosion(erodee);
    reconstruite = copie(vide);
    reconstruite = r_morphologique(courante, erodee);
    booleen(reconstruite, courante, residus, 2);
    courante = copie(erodes_ultimes);
    booleen(residus, courante, erodes_ultimes, 1);
    courante = copie(erodee);

  }while(memcmp(courante.pixels[0], vide.pixels[0], vide.lignes*vide.colonnes*sizeof(char)) != 0);

  libre(vide);
  libre(erodee);
  libre(residus);
  libre(reconstruite);
  libre(courante);
  return(erodes_ultimes);
}
