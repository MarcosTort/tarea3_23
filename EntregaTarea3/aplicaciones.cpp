#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista)
{
  TPilaPersona p = crearTPilaPersona();
  nat cantidad = cantidadTPersonasLDE(lista);
  if (lista != NULL)
  {
    TPersonasLDE aux = lista;
    for (nat i = 1; i <= cantidad; i++)
    {
      if (cantidadEnTPilaPersona(p) > 0)
      {

        if (edadTPersona(cimaDeTPilaPersona(p)) < edadTPersona(obtenerInicioDeTPersonasLDE(aux)))
        {
          apilarEnTPilaPersona(p, obtenerInicioDeTPersonasLDE(aux));
        }
        else
        {

          while (cantidadEnTPilaPersona(p) > 0 && edadTPersona(cimaDeTPilaPersona(p)) >= edadTPersona(obtenerInicioDeTPersonasLDE(aux)))
          {
            desapilarDeTPilaPersona(p);
          }
          apilarEnTPilaPersona(p, obtenerInicioDeTPersonasLDE(aux));
        }
      }
      else
      {

        apilarEnTPilaPersona(p, obtenerInicioDeTPersonasLDE(aux));
      }
      eliminarInicioTPersonasLDE(aux);
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