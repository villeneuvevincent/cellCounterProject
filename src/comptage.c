#include "picture.h"
#include "logique.h"
#include "reconstruction_m.h"

void dfs(IMAGE im, IMAGE visite, int l, int c){
  if (visite.pixels[l][c] == 0) {
    if (im.pixels[l][c] == 255) {
      visite.pixels[l][c] = 1;
      dfs(im, visite, l-1, c);
      dfs(im, visite, l+1, c);
      dfs(im, visite, l, c-1);
      dfs(im, visite, l, c+1);
    }
  }
}

int comptage(IMAGE im){
  IMAGE visite;
  visite = copie(im);
  int i, j;
  for (j= 0; j < im.lignes*im.colonnes; j++) {
    visite.pixels[0][j] = 0;
  }

  int count = 0;
  for (i = 1; i < im.lignes-1; i++) {
    for (j = 1; j < im.colonnes-1; j++) {
      if(visite.pixels[i][j] == 0){
        if (im.pixels[i][j] == 255) {
          count += 1;
        }
        dfs(im,visite, i,j);
      }
    }
  }

  libre(visite);
  return count;
}
