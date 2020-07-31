#ifndef INFORMES_INFORMES_H_
#define INFORMES_INFORMES_H_

void* setearMuertos(void*muertos);

void* setearInfectado(void*infected);

void* setearRecuperados(void*recu);

int filtrarExitoso(void*cantidad);

int filtrarPaisAlHorno(void*cantidad);

LinkedList* listaPaisesMasCastigados(LinkedList* this);

#endif /* INFORMES_INFORMES_H_ */
