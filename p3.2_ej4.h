#ifndef _GRAFO_H
#define _GRAFO_H

#include "conjunto.h"

struct repGrafo;
typedef repGrafo* Grafo;
typedef int Vertice;
struct repArista;
typedef repArista Arista;

Grafo CrearGrafo();
//devuelve el grafo vacio

void AgregarVertice(Grafo &g, Vertice v);
//inserta el vertice v en el grafo g
//Precondicion1: no exite el vertice v en el grafo g
//Precondicion2: o el vertice es 0 o existe el vertice v-1 en el grafo g

void QuitarVertice(Grafo &g, Vertice v);
//remueve el vertice v del grafo g
//Precondicion: existe el vertice v en el grafo g y no existe el vertice v+1


void AgregarArista(Grafo &g, Arista a);
//inserta la arista a en el grafo g
//Precondicion: existen los vertice a.v y a.w

void QuitarArista(Grafo &g, Arista a);
//Precondicion: existe la arista a en el grafo g

ConjuntoInt Vertices(Grafo g);

ConjuntoInt Adyacentes(Grafo g, Vertice v);

void destruirGrafo(Grafo &g);
// libera toda la memoria ocupada por g

#endif /* _GRAFO_H */
