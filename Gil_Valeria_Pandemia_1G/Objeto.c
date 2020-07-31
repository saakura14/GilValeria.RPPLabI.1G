#include <stdio.h>
#include "Objeto.h"

#include <stdlib.h>
#include <string.h>

//setters
int Objeto_setID(ePais *this, int *id)
{
	int todoOk = 0;

	if (this != NULL)
	{
		if (id >= 0)
		{
			this->id = *id;
			todoOk = 1;
		}
	}
	return todoOk;
}

int Objeto_setPais(ePais *this, char *pais)
{
	int todoOk = 0;

	if (this != NULL && pais != NULL)
	{
		strncpy(this->pais, pais, 10);
		todoOk = 1;
	}
	return todoOk;
}

int Objeto_setMuertos(ePais *this, int muertos)
{
	int todoOk = 0;

	if (this != NULL)
	{
		if (muertos >= 0)
		{
			this->muertos = muertos;
			todoOk = 1;
		}
	}
	return todoOk;
}

int Objeto_setRecuperados(ePais *this, int recu)
{
	int todoOk = 0;

	if (this != NULL)
	{
		if (recu >= 0)
		{
			this->recuperados = recu;
			todoOk = 1;
		}
	}
	return todoOk;
}

int Objeto_setInfectados(ePais *this, int infect)
{
	int todoOk = 0;

	if (this != NULL)
	{
		if (infect >= 0)
		{
			this->infectados = infect;
			todoOk = 1;
		}
	}
	return todoOk;
}

//getters
int Objeto_getID(ePais *this, int *id)
{
	int todoOk = 0;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int Objeto_getPais(ePais *this, char *pais)
{
	int todoOk = 0;

	if (this != NULL && pais != NULL)
	{
		strcpy(pais, this->pais);
		todoOk = 1;
	}
	return todoOk;
}

int Objeto_getInfectados(ePais *this, int *infectado)
{
	int todoOk = 0;

	if (this != NULL && infectado != NULL)
	{
		*infectado = this->infectados;
		todoOk = 1;
	}
	return todoOk;
}

int Objeto_getRecuperados(ePais *this, int *recuperado)
{
	int todoOk = 0;

	if (this != NULL && recuperado != NULL)
	{
		*recuperado = this->recuperados;
		todoOk = 1;
	}
	return todoOk;
}

int Objeto_getMuertos(ePais *this, int *muertos)
{
	int todoOk = 0;

	if (this != NULL && muertos != NULL)
	{
		*muertos = this->muertos;
		todoOk = 1;
	}
	return todoOk;
}

// Constructores
ePais* Objeto_new()
{
	ePais *nuevoObjeto;
	nuevoObjeto = (ePais*) calloc(sizeof(ePais), 1);

	return nuevoObjeto;
}

ePais* Objeto_newParam(char *id, char *pais, char *infectados,	char *recuperados, char* muertos)
{
	ePais *nuevoObjeto;
	nuevoObjeto = Objeto_new();

	int auxId;
	int auxrecuperados;
	int auxMuertos;
	int auxInfectados;

	auxId = atoi(id);
	auxrecuperados = atoi(recuperados);
	auxMuertos = atoi(muertos);
	auxInfectados = atoi(infectados);

	if (nuevoObjeto != NULL && id != NULL && pais != NULL && infectados != NULL && recuperados != NULL && muertos != NULL )
	{
		Objeto_setID(nuevoObjeto, &auxId);
		Objeto_setPais(nuevoObjeto, pais);
		Objeto_setInfectados(nuevoObjeto, auxInfectados);
		Objeto_setRecuperados(nuevoObjeto, auxrecuperados);
		Objeto_setMuertos(nuevoObjeto, auxMuertos);
	}
	return nuevoObjeto;
}

int Objeto_sortInfectados(void *infect1, void *infect2)
{
int infect_1;
int infect_2;
int todoOk = 0;

Objeto_getInfectados(infect1, &infect_1);
Objeto_getInfectados(infect2, &infect_2);

if (infect_1 > infect_2)
{
	todoOk = 1;
} else if (infect_1 < infect_2)
{
	todoOk = -1;
}
	return todoOk;
}
