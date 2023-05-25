#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista)
{
  TPilaPersona p = crearTPilaPersona();
  nat cantidad = cantidadTPersonasLDE(lista);
  if (lista != NULL)
  {
    TPersonasLDE aux = lista;
    apilarEnTPilaPersona(p, obtenerInicioDeTPersonasLDE(aux));
    
    for (nat i = 1; i <= cantidad; i++)
    {
      if (cantidadEnTPilaPersona(p) > 0)
      {

        if (edadTPersona(cimaDeTPilaPersona(p)) < edadTPersona(obtenerDeTPersonasLDE(aux, i)))
        {

          apilarEnTPilaPersona(p, obtenerDeTPersonasLDE(aux, i));
        }
        else
        {

          while (cantidadEnTPilaPersona(p) > 0 )
          {
            desapilarDeTPilaPersona(p);
          }
          apilarEnTPilaPersona(p, obtenerDeTPersonasLDE(aux, i));
        }
      }
      else
      {
        apilarEnTPilaPersona(p, obtenerDeTPersonasLDE(aux, i));
      }
    }
  }
  return p;
 
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