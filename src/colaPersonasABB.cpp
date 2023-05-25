#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"
struct celda {
  TPersonasABB persona;
  celda *siguiente;
};
struct rep_colaPersonasABB
{
  celda *primero;
  celda *ultimo;
  int cantidad;
};

TColaPersonasABB crearTColaPersonasABB()
{
    TColaPersonasABB nuevo = new rep_colaPersonasABB;
    nuevo->primero = NULL;
    nuevo->ultimo = NULL;
    nuevo->cantidad = 0;
    return nuevo;
}

void liberarTColaPersonasABB(TColaPersonasABB &c)
{
  celda *aux ;
  while (c->primero != NULL)
  {
    aux = c->primero;
    c->primero = c->primero->siguiente;
    delete aux;
  }
  delete c;
  c = NULL;
}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c)
{
  return c == NULL ? 0 : c->cantidad;
}

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c)
{
  celda *nuevo = new celda;
  nuevo->persona = t;
  nuevo->siguiente = NULL;
  if (c->primero == NULL)
  {
    c->primero = nuevo;
    c->ultimo = nuevo;
  }
  else
  {
    c->ultimo->siguiente = nuevo;
    c->ultimo = nuevo;
  }
  c->cantidad++;
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c)
{
  return c->primero->persona;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c)
{
  celda *aux = c->primero;
  c->primero = c->primero->siguiente;
  delete aux;
  c->cantidad--;
}
