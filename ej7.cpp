#include <stdlib.h>
#include "ej4.h"
#include "conjunto.h"

bool caminoEuleriano(Grafo g)
 {
  int i, impares;
  ConjuntoInt aux;

  aux = Vertices(g);
  i = cantidadElementosConjunto(aux);
  destruirConjunto(aux);
  for(i--; (i >= 0) && (impares < 3); i--)
   {
    aux = Adyacentes(g, i);
      if(cantidadElementosConjunto(aux) % 2)
        impares++;
    destruirConjunto(aux);
   }
  return !(impares % 2);
 }
