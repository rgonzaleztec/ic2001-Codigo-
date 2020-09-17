/* En este archivo se implementan todas las funciones para listas
*  Recordar que C++ te permite definir las funciones en cualquier parte del codigo
*  pero recuerde ser ordenado y documento las funciones
*/
#include <iostream>
// Implementaciones para funciones de listas Simples
#include "listas.h"


struct nodo* insertarListaS(float verX, float verY, struct nodo* sprimero)
{
	// Insertamos un nodo recordar que las listas simples insertan al inicio
	// Pueden hacer una funcion para insertar al final tambien

	struct nodo* nuevonodo = new nodo();
	nuevonodo->verticeX = verX;
	nuevonodo->verticeY = verY;
	nuevonodo->sig = sprimero;  // recordar que los struct se acceden de esta forma cuando son punteros
	return nuevonodo;       // modificamos la direccion del nuevo primero
	// Insertar es un funcion sensilla
	// El ultimo nodo de la lista debe estar siempre apuntando a null sino nos podemos lopear
}

void imprimirListaSNormal(struct nodo* sprimero)
{
	// Imprmir una lista simple no tiene mayor complejidad
	struct nodo* snodo = sprimero; // recuerden siempre iniciar sus variables con el tipo de datos
	
	while (snodo != nullptr)
	{
		// vamos a recorrer la lista imprimiendo en consola
		std::cout << snodo->verticeX << "," << snodo->verticeY << std::endl;
		snodo = snodo->sig; // nos movemos al siguiente

	}
}


// Vamos a imprimir la lista del ultimo al primero de manera recursiva :)
void imprimirListaSinversa(struct nodo* snodoinicial)
{
	// Esta es nuestra condiciones de parada para que nuestro algoritmo no se quede al indifinito
	// por eso nunca se debe dejar el puntero sig del ultimo nodo apuntando a otro nodo
	if (snodoinicial == NULL)
		return;

	imprimirListaSinversa(snodoinicial->sig);
	std::cout << snodoinicial->verticeX << "," << snodoinicial->verticeY << std::endl;

}

// La funcion de buscar es muy util cuando tenemos listas grandes o queremos
// insertar en otro lado, o cuando vamos a borrar
bool buscarVerticeLS(float fverX, float fverY, struct nodo* sprimero)
{
	// Si la lista esta vacia retornamos
	if (sprimero == nullptr)
	{
		std::cout << "Lista Vacia" << std::endl;
	}
	// Necesitamos un temporal para recorrer la lista
	// no queremo perder el inicio de lista

	struct nodo* nnodotemp = sprimero;
	while (nnodotemp != nullptr)
	{
		if ((nnodotemp->verticeX == fverX) && (nnodotemp->verticeY == fverY))
			return true;

		nnodotemp = nnodotemp->sig; // seguimos buscando
	}
	return false; // si no lo encontramos
}

// Fin de funciones de para lista simples

/*
	En adelante solo hasta que se indique solo se encontrar funciones para
	listas circulares, tendran una C que lo indica
*/

// Esta funcion debe ir buscando el nodo fin para apuntar ese nodo al inicio
struct nodo* insertarListaC(float verX, float verY, struct nodo* sprimero)
{
	struct nodo* nuevonodo = new nodo();
	nuevonodo->verticeX = verX;
	nuevonodo->verticeY = verY;

	// Si es el primer nodo que se inserta apunta a si mismo
	if (sprimero == NULL)
		nuevonodo->sig = nuevonodo;
	else
	{
		//necesitamos movernos en la lista
		struct nodo* snodotemp = sprimero;
		// podemos usar un do while ya que sabemos que tenemos almenos un elemento
		do
		{
			snodotemp = snodotemp->sig;
		} while (snodotemp->sig != sprimero);
		snodotemp->sig = nuevonodo;
		nuevonodo->sig = sprimero;
	}
	sprimero = nuevonodo;
	return sprimero;
}

// Debemos copiar cual es la direccion del primer nodo como es circular,
// sera nuestra unica referencia para no quedar en un ciclo continuo
void imprimirListaC(struct nodo* sprimero)
{
	struct nodo* snodotemp;
	if (sprimero == NULL)
		return;

	snodotemp = sprimero; // iniciamos en el primero
	do {
		std::cout << snodotemp->verticeX << "," << snodotemp->verticeY << std::endl;
		snodotemp = snodotemp->sig;
	} while (snodotemp != sprimero);

}