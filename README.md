# Cell Counter Project

The codes provided enable a pgm scanner image to be processed in order to count the number of cells present on it.
The data structures used are contiguously allocated arrays. This allows me, when reading or writing a file, to work with all the data at once, treating it as a single binary block. 
For thresholding, I used the Otsu method. It allows me to automatically determine the threshold value from the image histogram, the one that maximizes the inter-class variance.
To count the cells, I have considered that two pixels belong to the same connected component if they are in contact on one of their four sides.

For this project, I decided to program in C and use Valgrind to carry out memory tests and analysis, with a view to detecting
performance problems or program instability.




