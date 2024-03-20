#include "picture.h"
#include "seuillage.h"

int main(int argc, char** argv){
  IMAGE im;
  unsigned char* tab;

  if(argc != 2){
    fprintf(stderr, "Erreur\nUsage: ./bin/test_automatique NOM_FICHIER\n");
    exit(EXIT_FAILURE);
  }

  im = picture(argv[1]);

  tab = histogramme(im);

  unsigned char seuil;
  seuil = Otsu(tab);

  s_manuel(im , seuil);
  ecriture(im, "image/image_apres_seuillage.pgm");
  free(tab);
  libre(im);
  return 0;
  }
