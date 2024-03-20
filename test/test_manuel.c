// #include "picture.h"
// #include "seuillage.h"
//
// int main(){
//   IMAGE im;
//   im = picture("image/cellules_petit.pgm");
//   s_manuel(im , 155);
//   ecriture(im, "image/image_apres_s.pgm");
//   libre(im);
//   return 0;
// }

#include "picture.h"
#include "seuillage.h"

int main(int argc, char** argv){
  IMAGE im;
  int seuil = 0;

  if(argc != 3){
    fprintf(stderr, "Erreur\nUsage: ./bin/test_manuel SEUIL NOM_FICHIER\n");
    exit(EXIT_FAILURE);
  }

  seuil = atoi(argv[1]);
  im = picture(argv[2]);
  s_manuel(im , seuil);
  ecriture(im, "image/image_apres_seuillage_manuel.pgm");
  libre(im);
  return 0;
}
