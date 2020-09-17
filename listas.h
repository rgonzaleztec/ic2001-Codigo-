#pragma once
// Este encabezado nos permite crear las definiciones de las funciones
// crear las estructuras a utilizar para el manejo de cada tipo de lista
// es una forma ordenada de trabajar con listas

// Estructura de datos para lista simple
struct nodo {
	float verticeX; // vamos a manejar vertices para nuestras figuras
	float verticeY; // un vertice esta conformado por un par x,y
	struct nodo* sig;  // es una lista simple solo tiene un puntero al siguiente
}; 
// como se indico en las struct se puede definir aca variables iniciales
// estas se combierten en varias globales

// Definiciones de funciones para trabajar con listas simples

struct nodo* insertarListaS(float verX, float verY, struct nodo* sprimero);
void imprimirListaSNormal(struct nodo* sprimero);
void imprimirListaSinversa(struct nodo* snodoinicial);
bool buscarVerticeLS(float fverX, float fverY, struct nodo* sprimero);
// Deben implementar el borrado pista no pierdan los punteros ojo con eso


/* Ahora vamos a listar los metodos que son para listas circulares*/
// Los parametros no cambian pero la implementacion es diferente necesitamos apuntar
// fin al inicio
struct nodo* insertarListaC(float verX, float verY, struct nodo* sprimero);
// Ahora vamos a hacer un imprimir para circular no pierdas el pultero primero
void imprimirListaC(struct nodo* sprimero);

