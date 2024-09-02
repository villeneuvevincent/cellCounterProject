# Cell Counter Project

The codes provided enable a pgm scanner image to be processed in order to count the number of cells present on it.
The data structures used are contiguously allocated arrays. This allows me, when reading or writing a file, to work with all the data at once, treating it as a single binary block. 
For thresholding, I used the Otsu method. It allows me to automatically determine the threshold value from the image histogram, the one that maximizes the inter-class variance.
To count the cells, I have considered that two pixels belong to the same connected component if they are in contact on one of their four sides.

For this project, I program in C and use Valgrind to carry out memory tests and analysis, with a view to detecting
performance problems or program instability.

### Méthode d’Otsu

![Image et son histogramme](./image/img-readme/otsu.png)

**Figure 1 – The image and its histogram.**

The Otsu method lists all possible threshold values, from 0 to 255, and finds the one that maximizes the inter-class variance, i.e. the one that best separates the two modes. The inter-class variance \( \sigma_{b}^{2}(s) \) is defined in equation (1).

$$
\sigma_b^2(s) = \omega_0(s)\omega_1(s)[\mu_0(s) - \mu_1(s)]^2 \tag{1}
$$

où \( \omega_0(s) \) et \( \omega_1(s) \) sont les probabilités de classe, définies dans l’équation (2)

$$
\omega_0(s) = \sum_{i=0}^{s-1} h(i) \quad \text{et} \quad \omega_1(s) = \sum_{i=s}^{255} h(i) \tag{2}
$$

et \( \mu_0(s) \) et \( \mu_1(s) \) sont les moyennes empiriques des classes, définies dans l’équation (3).

$$
\mu_0(s) = \frac{\sum_{i=0}^{s-1} ih(i)}{\omega_0(s)} \quad \text{et} \quad \mu_1(s) = \frac{\sum_{i=s}^{255} ih(i)}{\omega_1(s)} \tag{3}
$$

Le seuil calculé est la valeur de \( s \) pour laquelle la variance inter-classe \( \sigma_b^2(s) \) est maximale.

Vous écrirez une fonction qui réalise le seuillage automatique, puis vous écrirez un programme de test qui permet de seuiller automatiquement une image dont le nom est passé en paramètre.






