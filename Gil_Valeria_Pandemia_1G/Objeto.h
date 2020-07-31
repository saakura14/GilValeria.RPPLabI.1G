
#ifndef Objeto_H_INCLUDED
#define Objeto_H_INCLUDED

typedef struct {
    int id;
	char pais[128];
	int recuperados;
	int infectados;
	int muertos;
} ePais;

//getters

/** \brief obtiene la cantidad de muertos del pais
 *
 * \param this es la lista de paises
 * \param muertos es el valor de muertos que tendra
 * \return 1 si pudo, 0 si error.
 *
 */

int Objeto_getMuertos(ePais *this, int *muertos);

/** \brief  obtiene la cantidad de recuperados de los paises
 *
 * \param   this es la lista de paises
 * \param   recuperados es el valor de recuperados que tendra
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getRecuperados(ePais *this, int *recuperado);

/** \brief obtiene la cantidad de infectados.
 *
 * \param   this es la lista de infectados
 * \param   infectado es el valor de infectados que habra
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getInfectados(ePais *this, int *infectado);

/** \brief obtiene la cantidad de paises que hay.
 *
 * \param   this es la lista de paises
 * \param   pais es el valor de paises
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getPais(ePais *this, char *pais);

/** \brief  le otroga el ID al pais
 *
 * \param   this es la lista de id
 * \param   id es el valor que le da al pais
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_getID(ePais *this, int *id);

//setters

/** \brief Coloca la cantidad de infectados
 *
 * \param this es el valor en la lista
 * \param   infectados es el valor que hay.
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setInfectados(ePais *this, int infectado);

/** \brief coloca la canridad de recuperados
 *
 * \param this es el valor en la lista
 * \param recuperados es el valor en la misma
 * \return 1 si se pudo, 0 el error
 *
 */


int Objeto_setRecuperados(ePais *this, int recuperado);

/** \brief coloca la cantidad de muertos
 *
 * \param   this puntero LinckedList
 * \param   muertos es el valor en la lista
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setMuertos(ePais *this, int muertos);

/** \brief permite colocar datos en la funcion
 *
 * \param   Thhis es puntero a la linkedList
 * \param   pais es el valor en la lista
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setPais(ePais *this, char *pais);

/** \brief coloca ID
 *
 * \param   Thhis es puntero a la linkedList
 * \param  id es el valir en la lista
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_setID(ePais *this, int *id);


//constructores
ePais* Objeto_new();
ePais* Objeto_newParam(char *id, char *pais, char *infectados,	char *recuperados, char* muertos);

/** \brief Nuevo parametro
 *
 * \param   id a evaluar
 * \param   pais a evaluar
 * \param   infectados  a evaluar
 * \param   recuperados a evaluar
 * \param   muertos a evaluar
 * \return  1 si se pudo, 0 el error
 *
 */

int Objeto_sortInfectados(void *infect1, void *infect2);

/** \brief ordena el array con el campo infectados
 *
 * \param infect1: primer numero a evaluar
 * \param infect2: segundo numero a evaluar
 * \return retorna 0 si son iguales, 1 si el segundo es menor y sino -1 si es mayor.
 *
 */


#endif // Objeto_H_INCLUDED
