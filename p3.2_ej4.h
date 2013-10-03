#ifndef _GRAFO_H
#define _GRAFO_H

struct repGrafo;
typedef repGrafo* Grafo;
typedef int Vertice;
typedef int[2] Arista;
struct repConjuntoV;
typedef repConjuntoV* ConjuntoDeVertices; 

Grafo CrearGrafo();
//devuelve el grafo vacio

void AgregarVertice(Grafo &g, Vertice v);
//inserta el vertice v en el grafo g
//Precondicion: o el vertice es 0 o existe el vertice v-1 en el grafo g

void QuitarVertice(Grafo &g, Vertice v);
//remueve el vertice v del grafo g
//Precondicion: existe el vertice v en el grafo g


void AgregarArista(Grafo &g, Arista a);
//inserta la arista a en el grafo g
//Precondicion: existen los vertice a[0] y a[1]

void QuitarArista(Grafo &g, Arista a);
//Precondicion: existe la arista a en el grafo g

ConjuntoDeVertices Vertices(Grafo g);

ConjuntoDeVertices Adyacentes(Grafo g, Vertice v);

void destruirGrafo(Grafo &g);
// libera toda la memoria ocupada por g

#endif /* _GRAFO_H */
