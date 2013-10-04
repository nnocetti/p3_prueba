#include <stdlib.h>
#include "ej4.h"
#include "conjunto.h"

void aux_prenumeraDFS(int v, Grafo g, ConjuntoInt &m, int* &prenum, int &cont)
 {
  int w;
  ConjuntoInt ady;
  
  agregarElementoConjunto(v, m);
  prenum[v]=++cont;
  ady = Adyacentes(g, v);
  iniciarRecorridaConjunto(ady);
  while (siguienteConjunto(w, ady))
    if (!perteneceConjunto(w, m))
	  prenumeraDFS(w, g, m, prenum, cont);
  destruirConjunto(ady);
 }

int* prenumeraDFS(int v, Grafo g)
 {
  int nv, cont, *prenum;
  ConjuntoInt aux;
  
  aux = Vertices(g);
  nv = cantidadElementosConjunto(aux);
  destruirConjunto(aux);
  prenum = new int[nv];
  aux = crearConjunto();
  cont = 0;
  aux_prenumeraDFS(v, g, aux, prenum, cont);
  destruirConjunto(aux);
  return prenum;
 }
 
int aux_calculamasalto(int v, Grafo g, ConjuntoInt &m, int* prenum, int p, int* &masalto)
 {
  int w, mahijo;
  ConjuntoInt ady;
  
  agregarElementoConjunto(v, m);
  masalto[v] = prenum[v];
  ady = Adyacentes(g, v);
  iniciarRecorridaConjunto(ady);
  while(siguienteConjunto(w, ady))
   {
    if (!perteneceConjunto(w, m))
	 {
	  mahijo = aux_puntosArt(w, g, m, v, prenum, pa);
	  if (mahijo < masalto[v])
        masalto[v] = mahijo;
     }		
    else if (w!=p)
     {
	  if (prenum[w] < masalto[v])
	    masalto[v] = prenum[w];
     }	 
   }
  destruirConjunto(ady);
  return masalto[v];
 }

int* calculamasalto(int v, Grafo g, int* prenum)
 {
  int nv, *masalto;
  ConjuntoInt aux;
  
  aux = Vertices(g);
  nv = cantidadElementosConjunto(aux);
  destruirConjunto(aux);
  masalto = new int[nv];
  aux = crearConjunto();
  v = aux_masalto(v, g, aux, prenum, v, masalto);
  destruirConjunto(aux);  
  return masalto;
 }

void aux_puntosArt(int v, Grafo g, int* prenum, int* masalto, ConjuntoInt &pa)
 {
  int w, maHijo;
  ConjuntoInt ady;
  
  agregarElementoConjunto(v, m);
  maHijo = -1;
  ady = Adyacentes(g, v);
  iniciarRecorridaConjunto(ady);
  while(siguienteConjunto(w, ady))
   {
    if (!perteneceConjunto(w, m))
	 {
	  if (masalto[w] > maHijo) maHijo = masalto[w];
      aux_puntosArt(w, g, prenum, masalto, pa);
     }		
   }
  destruirConjunto(ady);
  if (maHijo > prenum[v]) agregarElementoConjunto(v, pa);
 }

ConjuntoInt puntosArt(Grafo g)
 {
  int v, w, hijosraiz, *prenum, *masalto;
  ConjuntoInt aux, ady, pa;
  
  pa = crearConjunto();
  aux = Vertices(g);
  iniciarRecorridaConjunto(aux);
  if(siguienteConjunto(v, aux))
   {
    destruirConjunto(aux);   
    prenum = prenumeraDFS(v, g);
	masalto = calculamasalto(v, g, prenum);
    aux = crearConjunto();
	agregarElementoConjunto(v, aux);
	hijosraiz = 0;
	ady = Adyacentes(g, v);
	iniciarRecorridaConjunto(ady);
	while(siguienteConjunto(w, ady))
	 {
	  if (!perteneceConjunto(w, m))
	   { 
        aux_puntosArt(w, g, prenum, masalto, pa);
		hijosraiz++;
       }
     }
    destruirConjunto(ady);
	if (hijosraiz > 1)
	  agregarElementoConjunto(v, pa);
	delete(prenum);
    delete(masalto);
   }
  destruirConjunto(aux);
  return pa;
 }
