#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "utn.h"
#include "Objeto.h"
#include "Controller.h"
#include "Informes.h"

int menu() {
	int opcion;
	printf(	"    ABM PANDEMIA \n"
			"    _______________________________________________________________\n"
			"        Menu:\n"
            "    1 Cargar archivo.\n"
            "    2 Listar paises.\n"
            "    3 Poner estadisticas.\n"
            "    4 Filtrar por paises exitosos <5000 muertos.\n"
            "    5 Filtrar por paises en el horno triple de infectados que curados.\n"
            "    6 Ordenar por nivel de infeccion cantidad de infectados mayor a menor.\n"
            "    7 Mostrar mas castigado paises con mas cantidad de muertos.\n"
            "    8 Salir.\n");
	utn_getNumero(&opcion, "Elegir opcion 1-8:  ","Opcion incorrecta.\n", 1, 9, 5);

	return opcion;
}

int PANDEMIA() {

	char confirma;
	char respuesta = 's';
	int archivoAbierto = 0;
	char path[128];

	LinkedList* listaFiltrada= ll_newLinkedList();
	LinkedList* paisesMasCastigados = ll_newLinkedList();
	LinkedList* listaPaises = ll_newLinkedList();

	do {
		switch (menu()) {
		case 1: // Carga Archivo
			utn_getNombre(path, 128, "ingresar nombre de archivo sin extension (pandemia): \n", "    Nombre incorrecto.\n", 7);
			strcat(path,".csv");
			printf("El archivo sera: %s\n",path);
			if(archivoAbierto)
			{
				printf("Archivo abierto.\n");
			} else
			{
					if(!controller_loadFromText(path,listaPaises))
					{
						printf("error al cargar csv.\n");
					}
					else
					{
						printf("Datos cargados!.\n");
						archivoAbierto = 1;
					}
			}
			break;

		case 2: // Listar paises
			if(!archivoAbierto)
            {
				printf("Imposible listar paises, archivo sin cargar.");
			}else if(controller_ListObject(listaPaises))
			{
				printf("Paises listados!\n");
			}
			break;

		case 3: // Mapear datos
			if(!archivoAbierto){
				printf("error archivo sin cargar.\n");
			}else{
				listaPaises = ll_map(listaPaises, setearInfectado);
				listaPaises = ll_map(listaPaises, setearMuertos);
				listaPaises = ll_map(listaPaises, setearRecuperados);
				if(controller_ListObject(listaPaises))
                {
					printf("Estadisticas asignadas!.\n");
				}
			}
			break;

		case 4: // filtrar pais exitoso
			if(!archivoAbierto)
            {
				printf("no se puede filtrar, archivo sin abrir.\n");
			}else{
				listaFiltrada = ll_filter(listaPaises, filtrarExitoso);
				if(controller_ListObject(listaFiltrada))
				{
					controller_saveAsText("paisesExitosos.csv", listaFiltrada);
					printf("Paises con menos de 5000 muertos mostrados\n"
							"Lista guardada como paisesExitosos.csv\n");
				}
			}
			break;

		case 5: // filtrar paios con mas de 5000 muertos
			if(!archivoAbierto)
            {
				printf("Imposible filtrar pais al horno, abra el archivo.\n");
			}else{
				listaFiltrada = ll_filter(listaPaises, filtrarPaisAlHorno);
				if (controller_ListObject(listaFiltrada))
                {
					controller_saveAsText("paisesAlHorno.csv", listaFiltrada);
					printf("Mostrando paises de triple de infectados que curados.\n"
							"Lista guardada como paisesAlHorno.csv\n");
				}
			}
			break;

		case 6: // ordenar por infectados mayor a menor
			if(listaPaises==NULL || !archivoAbierto)
            {
				printf("lista vacia o archivo sin cargar.\n");
			}else if(!ll_sort(listaPaises, Objeto_sortInfectados, 0))
			{
				controller_ListObject(listaPaises);
				printf("Ordenado por Nivel de infeccion (mayor a menor).\n");
			}
			break;

		case 7: //paises mas castigados
			if(!archivoAbierto)
            {
				printf("Archivo sin cargar.\n");
			}else{
				paisesMasCastigados = listaPaisesMasCastigados(listaPaises);
				if(controller_ListObject(paisesMasCastigados))
				{
					printf("Paises mas Con mas muertes mostrados.\n");
				}
			}
			break;

		case 8: /* Salir */
			printf("desea salir? s/n: ");
			scanf("%c",&confirma);
			if(confirma=='s')
			{
                respuesta='n';
                ll_deleteLinkedList(listaFiltrada);
                ll_deleteLinkedList(listaPaises);
                ll_deleteLinkedList(paisesMasCastigados);
			}
			break;

		default:
			printf(	"Opcion incorrecta (hay que usar de 1 a 8).\n");
			break;

		}
		system("pause");
		system("cls");

	} while (respuesta == 's');

	return 0;
}
