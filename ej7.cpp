#include <stdlib.h>
#include "ej4.h"
#include "conjunto.h"

bool caminoEuleriano(Grafo g)
 {
  int i, impares;
  
  for(i = cantidadElementosConjunto(Vertices(g)) - 1; (i >= 0) && (impares < 3); i--);
    if(cantidadElementosConjunto(Adyacentes(g, i)) % 2)
	  impares++;
  return !(impares % 2);
 }
