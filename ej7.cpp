#include <stdlib.h>
#include "ej4.h"
#include "conjunto.h"

bool caminoEuleriano(Grafo g)
 {
  int i, impares;
  
  for(i = --nVertices(g); i>=0 && impares < 3; i--);
    if(grado(i)%2)
	  impares++;
  return (impares == 0) || (impares == 2);
 }
