#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

struct rep_colaPersonasABB
{
  TPersonasABB persona;
  TColaPersonasABB siguiente;
  int cantidad;
};

TColaPersonasABB crearTColaPersonasABB()
{
  return NULL;
}

void liberarTColaPersonasABB(TColaPersonasABB &c)
{
  if (c != NULL)
  {
    liberarTColaPersonasABB(c->siguiente);
    delete c;
    c = NULL;
  }
}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c)
{
  return c == NULL ? 0 : c->cantidad;
}

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c)
{
  if (c == NULL)
  {
    c = new rep_colaPersonasABB;
    c->persona = t;
    c->cantidad = 1;
    c->siguiente = NULL;
  }
  else
  {
    encolarEnTColaPersonasABB(t, c->siguiente);
    c->cantidad++;
  }
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c)
{
  return c->persona;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c)
{
  TColaPersonasABB aux = c;
  c = c->siguiente;
  delete aux;
}
