#include "picture.h"
#include "logique.h"

int main(int argc, char** argv){
  IMAGE im;


  if(argc != 2){
    fprintf(stderr, "Erreur\nUsage: ./bin/test_manuel NOM_FICHIER\n");
    exit(EXIT_FAILURE);
  }


  im = picture(argv[1]);
  im = erosion_u(im);
  ecriture(im, "image/image_apres_erosion_u.pgm");

  libre(im);
  return 0;
}
