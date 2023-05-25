#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona
{
  TPersonasLDE personas;
};

TPilaPersona crearTPilaPersona()
{
  TPilaPersona p = new rep_pilaPersona;
  p->personas = crearTPersonasLDE();
  return p;
}

void liberarTPilaPersona(TPilaPersona &p)
{
  liberarTPersonasLDE(p->personas);
  delete p;
  p = NULL;
}

nat cantidadEnTPilaPersona(TPilaPersona p)
{
  return cantidadTPersonasLDE(p->personas);
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona)
{
  insertarFinalDeTPersonasLDE(p->personas, copiarTPersona(persona));
}

TPersona cimaDeTPilaPersona(TPilaPersona p)
{
  return obtenerFinalDeTPersonasLDE(p->personas);
}

void desapilarDeTPilaPersona(TPilaPersona &p)
{
  eliminarFinalTPersonasLDE(p->personas);
}
