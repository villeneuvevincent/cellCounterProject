#include "picture.h"
#include "logique.h"

IMAGE r_morphologique(IMAGE im, IMAGE gr){

IMAGE im1, imr = copie(im);
IMAGE gr_dilatee = copie(gr);

dilatation(gr_dilatee);
booleen(im, gr_dilatee, imr, 0);

do{

  im1 = copie(imr);
  gr_dilatee = copie(imr);
  dilatation(gr_dilatee);
  booleen(im, gr_dilatee, imr, 0);

}while (memcmp(imr.pixels[0], im1.pixels[0], im.lignes*im.colonnes*sizeof(char)) != 0);

libre(im1); libre(gr_dilatee);
im = copie(imr);
return imr;
}


void cadre(IMAGE graine){

  int i, j;
  //intérieur noir / contour blanc
  for (i = 0; i < graine.lignes ; i++) {
    for (j = 0; j < graine.colonnes; j++) {
      if (j == 0 || i == 0 || i == graine.lignes -1 || j == graine.colonnes -1) {
        graine.pixels[i][j] = 255;
      }
      else{graine.pixels[i][j] = 0;}
    }
  }
}


IMAGE supp_bord(IMAGE im){
  IMAGE graine=copie(im), im_bord;

  cadre(graine);
  im_bord = r_morphologique(im, graine);

  booleen(im, im_bord, graine, 2);

  im = copie(graine);
  libre(graine);
  libre(im_bord);
  return im;
}


void inversion(IMAGE im){
  int j;
  for ( j = 0; j < im.lignes*im.colonnes; j++) {
      im.pixels[0][j] = 255 - im.pixels[0][j];
  }

}


IMAGE boucher_trou(IMAGE im){
    IMAGE graine=copie(im);
    inversion(im);

    cadre(graine);
    im = r_morphologique(im,graine);
    inversion(im);

    libre(graine);
    return im;
}
