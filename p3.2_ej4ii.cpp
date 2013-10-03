#include <stdlib.h>
#include "ej4.h"
#include "conjunto.h"

typedef int Vertice;

struct nodoV
 {
  Vertice v;
  nodoV *sig;
 };

struct repGrafo
 {
  int nv;
  nodoV **l;
 };
 
struct repArista
 {
  Vertice v, w;
 };

Grafo CrearGrafo()
//devuelve el grafo vacio
 {
  repGrafo *g = NULL;
  
  return g;
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
  ng->l = new nodoV* [ng->nv];
  for (i = 0; i < v; i++)
    ng->l[i] = g->l[i];
  ng->l[v] = NULL;
  delete(g);
  g=ng;
 }

void destruirListaAdy(nodoV* &l);
 {
  nodoV *elm;
  
  while (l!=NULL)
   {
    elm = l;
    l = l->sig;
	delete(elm);
   }
 }

void QuitarVertice(Grafo &g, Vertice v)
//remueve el vertice v del grafo g
//Precondicion: existe el vertice v en el grafo g y no existe el vertice v+1
 {
  int i;
  repGrafo *ng;
  
  ng = new repGrafo;
  ng->nv = --v;
  ng->l = new nodoV* [v];
  for (i = 0; i < v; i++)
    ng->l[i] = g->l[i];
  destruirListaAdy(g->l[v]);
  delete(g->l);
  delete(g);
  g=ng;	
 }

void insertarAdy(nodoV* &l, Vertice v); 
 {
  nodoV *ady;
  
  ady = new nodoV;
  ady->v = v;
  ady->sig = l;
  l = ady;
 } 
 
void borrarAdy(nodoV* &l, Vertice v);
 {
  nodoV *aux, *elm;

  aux = l;
  if (l->v == v)
   {
	l = l->sig;
	delete(aux);
   }
  else
   {  
    while (aux->sig->v!=v)
      aux = aux->sig;
	elm = aux->sig;
	aux->sig = elm->sig;
	delete(elm);
   }
 }
 
void AgregarArista(Grafo &g, Arista a)
//inserta la arista a en el grafo g
//Precondicion1: existen los vertice a.v y a.w
//Precondicion2: no existe la arista a
 {
  insertarAdy(g->l[a.v], a.w);
  insertarAdy(g->l[a.w], a.v);
 }
 
void QuitarArista(Grafo &g, Arista a)
//Precondicion: existe la arista a en el grafo g
 {
  borrarAdy(g->l[a.v], a.w);
  borrarAdy(g->l[a.w], a.v);
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
  nodoV *aux;
  ConjuntoInt c;
  
  c = crearConjunto();
  for (aux = g->l[v]; aux!=NULL; aux=aux->sig)
    agregarElementoConjunto(aux->v, c);
  return c;
 }
 
void destruirGrafo(Grafo &g)
// libera toda la memoria ocupada por g
 {
  int i;
   
  for (i = 0; i < g->nv; i++)
    destruirListaAdy(g->l[i]);
  delete(g->l);
  delete(g);
  g = NULL;
 }
