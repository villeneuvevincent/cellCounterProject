#include "logique.h"
#include "seuillage.h"
#include "reconstruction_m.h"
#include "comptage.h"

int main(int argc, char** argv){
  IMAGE im;
  unsigned char* tab;

  if(argc != 2){
    fprintf(stderr, "Erreur\nUsage: ./bin/test_logique NOM_FICHIER\n");
    exit(EXIT_FAILURE);
  }

  im = picture(argv[1]);
  tab = histogramme(im);

  unsigned char seuil;
  seuil = Otsu(tab);
  free(tab);
  printf("\n%d\n", seuil );

  s_manuel(im , seuil);
  ecriture(im, "image/image_apres_s.pgm");
  im = boucher_trou(im);
  ecriture(im, "image/trou_bouche.pgm");
  im = supp_bord(im);
  ecriture(im, "image/bord_sup.pgm");
  erosion_m(im, 7);
  im = erosion_u(im);
  dilatation(im);
  ecriture(im, "image/final.pgm");

  int nombre;
  nombre = comptage(im);
  printf("%d\n", nombre);
  libre(im);
  return 0;
}
