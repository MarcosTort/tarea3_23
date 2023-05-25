#include "../include/conjuntoIds.h"

struct rep_conjuntoIds
{

	// array
	nat *array;
	nat cantMax;
	nat cantElem;
};

TConjuntoIds crearTConjuntoIds(nat cantMax)
{

	TConjuntoIds c = new rep_conjuntoIds;
	c->array = new nat[cantMax];
	c->cantMax = cantMax;
	c->cantElem = 0;
	for (nat i = 0; i < cantMax; i++)
	{
		c->array[i] = 0;
	}
	return c;
};

bool esVacioTConjuntoIds(TConjuntoIds c)
{
	return c->cantElem == 0;
};

void insertarTConjuntoIds(nat id, TConjuntoIds &c)
{
	if (c->cantElem > c->cantMax || id > c->cantMax || id == 0)
		return;

	c->array[id - 1] = id;
	c->cantElem++;
};

void borrarTConjuntoIds(nat id, TConjuntoIds &c)
{
	if (id > c->cantMax || c->cantElem == 0)
		return;

	c->array[id - 1] = 0;
	c->cantElem--;
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c)
{
	if (id > c->cantMax || c->cantElem == 0 || id == 0)
		return false;
	return c->array[id - 1] != 0;
};

nat cardinalTConjuntoIds(TConjuntoIds c)
{
	return c->cantElem;
};

nat cantMaxTConjuntoIds(TConjuntoIds c)
{
	return c->cantMax;
};

void imprimirTConjuntoIds(TConjuntoIds c)
{
	for (nat i = 0; i < c->cantMax; i++)
	{
		if (c->array[i] != 0)
			printf("%d ", c->array[i]);
		if (i == c->cantMax - 1)
			printf("\n");
	}
};

void liberarTConjuntoIds(TConjuntoIds &c)
{
	if (c == NULL)
		return;
	delete[] c->array;
	delete c;
	c = NULL;
};

TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{

	TConjuntoIds c = crearTConjuntoIds(c1->cantMax + c2->cantMax);
	for (nat i = 0; i < 2 * c1->cantMax; i++)
	{
		insertarTConjuntoIds(c1->array[i], c);
		insertarTConjuntoIds(c2->array[i], c);
	}
	return c;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{
	TConjuntoIds c = crearTConjuntoIds(c1->cantMax);
	for (nat i = 1; i < c1->cantMax; i++)
	{
		if (perteneceTConjuntoIds(i, c1) && perteneceTConjuntoIds(i, c2))
		{
			insertarTConjuntoIds(i, c);
		}
	}

	return c;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{

	TConjuntoIds c = crearTConjuntoIds(c1->cantElem);
	for (nat i = 0; i < c1->cantElem; i++)
	{
		if (!perteneceTConjuntoIds(c1->array[i], c2))
		{
			insertarTConjuntoIds(c1->array[i], c);
		}
	}
	return c;
};
