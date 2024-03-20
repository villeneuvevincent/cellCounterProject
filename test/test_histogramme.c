#include "picture.h"
#include "seuillage.h"

// int main(){
//   IMAGE im;
//   im = picture("image/image.pgm");
//   histogramme(im);
//   libre(im);
//   return 0;
// }

int main(int argc, char** argv){
  IMAGE im;
  unsigned char* tab;

  if(argc != 2){
    fprintf(stderr, "Erreur\nUsage: ./bin/test_automatique NOM_FICHIER\n");
    exit(EXIT_FAILURE);
  }

  im = picture(argv[1]);

  tab = histogramme(im);
  int i;
  for (i = 0; i < 256; i++) {
    printf("%d\n", tab[i] );
  }

  unsigned char seuil;
  seuil = Otsu(tab);

  printf("\n ========== \n");
  printf("\n%d\n", seuil);

  free(tab);
  libre(im);
  return 0;
  }
