#include <stdlib.h>
#include "ej4.h"
#include "conjunto.h"

struct repGrafo
 {
  int nv;
  char **m;
 };
 
struct repArista
 {
  int v, w;
 }

typedef int Vertice;

Grafo CrearGrafo()
//devuelve el grafo vacio
 {
  repGrafo *g = NULL;
  
  return g;
 }

void copiarNGrafo(n, go, &gd)
 {
  int i, j;
  
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
	  gd->m[i][j]=go->[i][j];
 }

void AgregarVertice(Grafo &g, Vertice v)
//inserta el vertice v en el grafo g
//Precondicion1: no exite el vertice v en el grafo g
//Precondicion2: o el vertice es 0 o existe el vertice v-1 en el grafo g
 {
  int i;
  repGrafo *ng;
  
  ng = new repGrafo;
  ng->nv = v + 1;
  ng->m = new char* [ng->nv];
  for (i = 0; i < ng->nv; i++)
    ng->m[i] = new char[ng->nv];
  if (v)
   {
    copiarNGrafo(v, g, ng);
	destruirGrafo(g);
   }
  for (i = 0; i < ng->nv; i++)
    ng->m[v][i] = 0;
  g=ng;
 }
 
void QuitarVertice(Grafo &g, Vertice v)
//remueve el vertice v del grafo g
//Precondicion: existe el vertice v en el grafo g y no existe el vertice v+1
 {
  int i;
  repGrafo *ng;
  
  ng = new repGrafo;
  ng->nv = --v;
  ng->m = new char* [v];
  for (i = 0; i < v; i++)
    ng->m[i] = new char[v];
  copiarNGrafo(v, g, ng);
  destruirGrafo(g);
  g=ng;	
 }

void AgregarArista(Grafo &g, Arista a)
//inserta la arista a en el grafo g
//Precondicion: existen los vertice a.v y a.w
 {
  g->m[a.v][a.w] = g->[a.w][a.v] = 1;
 }
 
void QuitarArista(Grafo &g, Arista a)
//Precondicion: existe la arista a en el grafo g
 {
  g->m[a.v][a.w] = g->[a.w][a.v] = 0;
 }
 
ConjuntoInt Vertices(Grafo g)
 {
  int i;
  ConjuntoInt c;
  
  c = crearConjunto();
  for (i = 0; i < g->nv; i++)
    agregarElementoConjunto(i, c);
  return c;
 }
 
ConjuntoInt Adyacentes(Grafo g, Vertice v)
 {
  int i;
  ConjuntoInt c;
  
  c = crearConjunto();
  for (i = 0; i < g->nv; i++)
    if (g->m[v][i])
	  agregarElementoConjunto(i, c);
  return c;
 }
 
void destruirGrafo(Grafo &g)
// libera toda la memoria ocupada por g
 {
  int i;
  
  for (i = 0; i < g->nv; i++)
    delete(g->m[i]);
  delete(g->m);
  delete(g);
  g = NULL;
 }
