# Compter les cellules d'une image scanner


Ce programme compte les cellules d'une image .PGM

## Compilation

`make`

## Utilisation

`./bin/test_logique NOM_FICHIER ` 

- `NOM_FICHIER` : nom du fichier  


## Tests

    $ ./bin/test_histogramme NOM_FICHIER

    $ ./bin/test_inversion NOM_FICHIER

    $ ./bin/test_automatique NOM_FICHIER

    $ ./bin/test_manuel SEUIL NOM_FICHIER

    $ ./bin/test_erosion_m SEUIL NOM_FICHIER

    $ ./bin/test_erosion NOM_FICHIER

    $ ./bin/test_picture NOM_FICHIER

### Exemple 
 `./bin/test_automatique image/cellule`
   $ ./bin/test_automatique image/cellules_petits.PGM

Return image/image_apres_seuillage_auto.pgm

## Fuite de mémoire 

    $ valgrind bin/test_TEST (SEUIL) NOM_FICHIER


