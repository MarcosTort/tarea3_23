#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista)
{
  TPilaPersona p = crearTPilaPersona();
  nat cantidad = cantidadTPersonasLDE(lista);
  if (lista != NULL)
  {
    apilarEnTPilaPersona(p, obtenerInicioDeTPersonasLDE(lista));
    nat cantidadP = cantidadEnTPilaPersona(p);

    for (nat i = 1; i <= cantidad; i++)
    {
    TPersona persona = obtenerDeTPersonasLDE(lista, i);
      if (cantidadP > 0)
      {

        if (edadTPersona(cimaDeTPilaPersona(p)) < edadTPersona(persona))
        {

          apilarEnTPilaPersona(p, persona);
        }
        else
        {

          while (cantidadP > 0 && edadTPersona(cimaDeTPilaPersona(p)) >= edadTPersona(persona))
          {
            desapilarDeTPilaPersona(p);
          }
          apilarEnTPilaPersona(p, persona);
        }
      }
      else
      {

        apilarEnTPilaPersona(p, persona);
      }
    }
  }
  return p;
  // int cantidad = cantidadTPersonasLDE(lista);
  // TPilaPersona pila = crearTPilaPersona();
  // apilarEnTPilaPersona(pila, obtenerDeTPersonasLDE(lista, 1));
  // for (int i = 2; i <= cantidad; i++)
  // {
  //     TPersona persona = obtenerDeTPersonasLDE(lista, i);
  //     TPersona persona2 = obtenerDeTPersonasLDE(lista, i + 1);
  //     if (persona2 == NULL)
  //     {
  //         break;
  //     }
  //     if (edadTPersona(persona) < edadTPersona(persona2))
  //     {
  //         apilarEnTPilaPersona(pila, persona);
  //     }
  //     else
  //     {
  //         while (cantidadEnTPilaPersona(pila))
  //         {
  //             desapilarDeTPilaPersona(pila);
  //         }
  //         apilarEnTPilaPersona(pila, persona2);
  //     }
  // }
  // return pila;
}
// k = c1 + c2
// c1 = k - c2

// Función que determina si hay un par de ids pertenecientes a "c" tales que su suma es igual a "k"
bool sumaPares(nat k, TConjuntoIds c)
{

  for (nat i = 1; i <= cantMaxTConjuntoIds(c); i++)
  {
    if (perteneceTConjuntoIds(k - i, c) && perteneceTConjuntoIds(i, c) && i != k - i)
    {
      return true;
    }
  }

  return false;
}