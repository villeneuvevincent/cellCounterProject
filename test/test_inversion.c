#include "picture.h"
#include "reconstruction_m.h"

// int main(){
//   IMAGE im;
//   im = picture("bord_sup.pgm");
//   im = inversion(im);
//   ecriture(im, "i_bord_sup.pgm");
//   libre(im);
//   return 0;
// }

int main(int argc, char** argv){
  IMAGE im;

  if(argc != 2){
    fprintf(stderr, "Erreur\nUsage: ./bin/test_automatique NOM_FICHIER\n");
    exit(EXIT_FAILURE);
  }

  im = picture(argv[1]);

  inversion(im);

  ecriture(im, "image/image_apres_inversion.pgm");
  libre(im);
  return 0;
}
