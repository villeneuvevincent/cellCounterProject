#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "picture.h"


//Allocation contigue de matrice
unsigned char** allocation(int l, int c){
  int i;
  unsigned char** p;

  p = (unsigned char **)calloc(l,sizeof(*p));
  if (p==NULL){return NULL;}

  else{
    *p= (unsigned char *)calloc(l*c, sizeof(**p));
    if (*p == NULL){ free(p); return NULL;}
    else
      {for (i=1; i<l; i++) p[i] = (p[i-1]+c);}
  }
  return p;
}


IMAGE picture(char* file){
  IMAGE im;

//Ouverture fichier
  FILE* f=fopen(file ,"rb");
  if (f==NULL){
    perror("Erreur : ouverture fichier\n");
    exit(EXIT_FAILURE);
  }

  else {

//Verification .PGM
     char t[2];
     fread(t,sizeof(char),2,f);
     if (t[0] != 'P' || t[1] != '5'){
       perror("Erreur : type fichier\n");
       exit(EXIT_FAILURE);
     }

    //Lecture ligne colonne et depth
      fscanf(f, "%d %d %d ", &im.colonnes, &im.lignes, &im.max);
      if (im.max != 255){
        perror("Erreur : Valeur max pixels\n");
        exit(EXIT_FAILURE);
      }

    //Ecriture fichier (allocation contigue)
      im.pixels = allocation(im.lignes,im.colonnes);

     /*int i,j; char x;
      for (i=0; i< im.lignes; i++){
        for (j=0; j< im.colonnes; j++){
          fread(&x, sizeof(char) ,1 ,f);
          im.pixels[i][j] =  x;

        }
      } */
    fread(im.pixels[0], sizeof(char),im.lignes*(im.colonnes+1), f);

    }
    //fermeture fichier
      if (fclose (f) != 0){
        perror("Erreur : fermeture fichier\n");
        exit(EXIT_FAILURE);
      }

      return im;
  }

//Libérez Délivrez
void libre(IMAGE im){
  free(im.pixels[0]);
  free(im.pixels);
  }

//ecriture de l'image dans un nouveau fichier
void ecriture(IMAGE im, char* copie){
//Ouverture fichier en écriture
  FILE* fw=fopen(copie ,"wb");
  if (fw==NULL){
    perror("Erreur : ouverture fichier\n");
    exit(EXIT_FAILURE);
  }

  else {
    fprintf(fw,"P5\n%d %d\n%d\n",im.colonnes, im.lignes, im.max);

    /*int i;
    for (i=0; i<im.lignes; i++){*/
    fwrite(im.pixels[0],sizeof(char),im.lignes*im.colonnes,fw);
    /*  } */


  //fermeture fichier
  if (fclose (fw) != 0){
    perror("Erreur : fermeture fichier\n");
    exit(EXIT_FAILURE);
    }
   }
  }

IMAGE copie(IMAGE im){
  IMAGE copie;

  //Copie paramètres PGM
  copie.lignes = im.lignes;
  copie.colonnes = im.colonnes;
  copie.max = im.max;

  //Allocation cotigue de la Copie
  copie.pixels = allocation(copie.lignes,copie.colonnes);

  //Copie de l'image dans copie
  memcpy(*copie.pixels,*im.pixels,sizeof(unsigned char)*copie.lignes*copie.colonnes);

  return copie;
}
