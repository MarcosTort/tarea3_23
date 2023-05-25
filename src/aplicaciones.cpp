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
      if (cantidadEnTPilaPersona(p)>0)
      {

        if (edadTPersona(cimaDeTPilaPersona(p)) < edadTPersona(obtenerDeTPersonasLDE(aux,i)))
        {

          apilarEnTPilaPersona(p, obtenerDeTPersonasLDE(aux,i));
        }
        else
        {

          while (cantidadEnTPilaPersona(p)>0&& edadTPersona(cimaDeTPilaPersona(p)) >= edadTPersona(obtenerDeTPersonasLDE(aux,i)))
          {
           desapilarDeTPilaPersona(p);
          }
          apilarEnTPilaPersona(p, obtenerDeTPersonasLDE(aux,i));
        }
      }
      else
      {

          apilarEnTPilaPersona(p, obtenerDeTPersonasLDE(aux,i));
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
   TConjuntoIds paresDeK = crearTConjuntoIds(k);
   TConjuntoIds paresDeC = interseccionTConjuntoIds(c, paresDeK);

    for (nat i = 1; i <= cantMaxTConjuntoIds(paresDeC); i++)
    {
        if (perteneceTConjuntoIds(k - i, paresDeC))
        {
          liberarTConjuntoIds(paresDeK);
          liberarTConjuntoIds(paresDeC);
          return true;
        }
      else
      {
        liberarTConjuntoIds(paresDeK);
        liberarTConjuntoIds(paresDeC);
        return false;
      }
    }
    

   

    
}