#include "picture.h"


int main(){
  IMAGE im;
  im = picture("image/cellules_petit.pgm");
  ecriture(im, "image/t_image.pgm");
  libre(im);
  return 0;
}
