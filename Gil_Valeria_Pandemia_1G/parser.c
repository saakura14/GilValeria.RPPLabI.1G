#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Objeto.h"

int parser_ObjectFromText(FILE *pFile, LinkedList *this) {
	ePais *pObjeto;
	char auxID[128];
	char pais[128];
	char infectados[128];
	char recuperados[128];
	char muertos[128];

	int todoOk = 0;
	int primerLinea = 1;

	if (pFile != NULL) {
		while (!feof(pFile))
        {
			if (primerLinea)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, pais, recuperados, infectados, muertos);
				primerLinea = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, pais, recuperados, infectados, muertos);
			pObjeto = Objeto_newParam(auxID, pais,recuperados, infectados,muertos);

			if (pObjeto != NULL)
            {
				ll_add(this, pObjeto);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}
