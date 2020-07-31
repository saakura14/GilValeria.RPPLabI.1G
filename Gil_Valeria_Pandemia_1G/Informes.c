#include <stdio.h>
#include <stdlib.h>

#include "Objeto.h"
#include "LinkedList.h"

int getMuertosAleatorio(void){
	int aleatorio;
	//1000 - 50000
	aleatorio = rand()% (1000 + 49001);

	return aleatorio;
}

int getInfectadosAleatorios(void){
	int aleatorio;
	//40000 - 2000000
	aleatorio = rand()% (40000 + 1960001);

	return aleatorio;
}

int getRecuperadosAleatorios(void){
	int aleatorio;
	//50000 - 1000000
	aleatorio = rand()% (50000 + 950001);

	return aleatorio;
}

void* setearMuertos(void*muertos){
	ePais* muerto = NULL;

	if(muertos!=NULL){
		muerto = (ePais*)muertos;
		Objeto_setMuertos(muerto, getMuertosAleatorio());

	}
	return muerto;
}

void* setearInfectado(void*infected){
	ePais* infectado = NULL;

	if(infected!=NULL){
		infectado = (ePais*)infected;
		Objeto_setInfectados(infectado, getInfectadosAleatorios());

	}
	return infectado;
}

void* setearRecuperados(void*recu){
	ePais* recuperado = NULL;

	if(recu!=NULL){
		recuperado = (ePais*)recu;
		Objeto_setRecuperados(recuperado, getRecuperadosAleatorios());
	}
	return recuperado;
}

int filtrarExitoso(void*cantidad){
	int todoOk = 0;

	ePais* exitoso;
	if(cantidad!=NULL){
		exitoso = (ePais*)cantidad;
		if(exitoso->muertos<5000){
			todoOk = 1;
		}
	}

	return todoOk;
}

int filtrarPaisAlHorno(void*cantidad){
	int todoOk = 0;
	int recuperados;
	int infectados;

	ePais* horno;
	if(cantidad!=NULL){
		horno = (ePais*)cantidad;
		Objeto_getInfectados(horno, &infectados);
		Objeto_getRecuperados(horno, &recuperados);
		if(infectados >= (recuperados*3)){
			todoOk = 1;
		}
	}

	return todoOk;
}

LinkedList* listaPaisesMasCastigados(LinkedList* this){
	LinkedList* listaMapeada = NULL;
	int muertosActual;
	int muertosMayorCant;
	int flag = 0;
	ePais* pElement = NULL;

	if(this!=NULL){
		listaMapeada = ll_newLinkedList();
		for(int i = 0;i<ll_len(this);i++){
			pElement = ll_get(this, i);
			Objeto_getMuertos(pElement, &muertosActual);
			if(!flag || muertosActual > muertosMayorCant){
				muertosMayorCant = muertosActual;
				flag = 1;
			}
		}
        for(int i = 0;i<ll_len(this);i++){
			pElement = ll_get(this, i);
			Objeto_getMuertos(pElement, &muertosActual);
			if(muertosActual==muertosMayorCant){
				ll_add(listaMapeada, pElement);
			}
		}
	}

	return listaMapeada;
}
