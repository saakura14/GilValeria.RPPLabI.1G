#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Objeto.h"
#include "parser.h"

int controller_loadFromText(char *path, LinkedList *this) {
	FILE *pFile;

	int todoOk = 0;
	pFile = fopen(path, "r");
	if (pFile != NULL) {
		if(parser_ObjectFromText(pFile, this)){
			fclose(pFile);
			todoOk = 1;
		}
		else{
			printf("No se puedo parsear el archivo de Texto.");
		}

	}else{
		printf("Archivo es NULL");
	}

	return todoOk;
}

int controller_ListObject(LinkedList *this) {
	ePais *pObjeto;
	int todoOk = 0;
	int id;
	char pais[128];
	int infectados;
	int muertos;
	int recuperados;

	if (this == NULL) {
		printf("\nNo se puede listar objetos , la lista es NULL.\n");
	} else {
		printf("ID      Pais     Recuperados     Infectados     Muertos \n"
               "___________________________________________________________________\n");
		todoOk = 1;

		for (int i = 0; i < ll_len(this); i++) {
			pObjeto = ll_get(this, i);
			Objeto_getID(pObjeto, &id);
			Objeto_getInfectados(pObjeto, &infectados);
			Objeto_getMuertos(pObjeto, &muertos);
			Objeto_getRecuperados(pObjeto, &recuperados);
			Objeto_getPais(pObjeto, pais);
			printf("    %3d %10s %8d %8d %8d\n", id, pais, recuperados, infectados, muertos);
		}
	}
	return todoOk;
}

int guardarComoTexto(FILE *pFile, LinkedList *this) {
	ePais *pObjeto;

	int id;
	char pais[128];
	int infectados;
	int muertos;
	int recuperados;
	int len_LL;
	int todoOk = 0;
	int flagHeader = 1;

	if (pFile != NULL && this != NULL) {
		len_LL = ll_len(this);

		for (int i = 0; i < len_LL; i++) {
			pObjeto = ll_get(this, i);
			Objeto_getID(pObjeto, &id);
			Objeto_getInfectados(pObjeto, &infectados);
			Objeto_getMuertos(pObjeto, &muertos);
			Objeto_getRecuperados(pObjeto, &recuperados);
			Objeto_getPais(pObjeto, pais);

			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s\n", "id", "nombre", "recuperados", "infectados", "muertos");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%s,%d,%d,%d\n", id, pais,recuperados, infectados, muertos);
			todoOk = 1;
		}
	}
	else{
		printf("El archivo o el array son NULL.\n");
	}
	return todoOk;
}

int controller_saveAsText(char *path, LinkedList *this) {
	int todoOk = 0;
	FILE *pFile = fopen(path, "w");

	if (pFile != NULL && guardarComoTexto(pFile, this)) {
		todoOk = 1;
	}
	fclose(pFile);
	ll_clear(this);
	return todoOk;
}
