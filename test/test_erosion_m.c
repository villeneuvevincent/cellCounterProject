#include "picture.h"
#include "logique.h"

int main(int argc, char** argv){
  IMAGE im;
  int seuil;

  if(argc != 3){
    fprintf(stderr, "Erreur\nUsage: ./bin/test_manuel SEUIL NOM_FICHIER\n");
    exit(EXIT_FAILURE);
  }

  seuil = atoi(argv[1]);
  im = picture(argv[2]);
  erosion_m(im,seuil);
  ecriture(im, "image/image_apres_erosion_m.pgm");

  libre(im);
  return 0;
}
