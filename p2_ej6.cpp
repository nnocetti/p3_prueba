#include <stdio.h>

int buscar(int i, int *a, int n)
// Precondicion: el entero i debe encontrarse en el arreglo a
 {
  
  while (a[--n]!=i);
  return i;
 }
