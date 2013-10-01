#include <stdio.h>

int buscar(int i, int *a, int n)
 {
  
  while (a[--n]!=i);
  return i;
 }
