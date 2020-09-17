// listasDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "listas.h"

struct nodo * snodoinicial;
struct nodo* snodoCircularinicial;

// se declaran aca para que el compilador no de error
void demoListasCirculares();
void demoListasSimples();


int main()
{
    int iselec;
    
    do
    {
        std::cout << std::endl << std::endl;
        std::cout << "Demo de listas!" << std::endl;
        std::cout << "Seleccione una opcion" << std::endl;
        std::cout << "1) Listas Simples" << std::endl;
        std::cout << "2) Listas Circulares" << std::endl;
        std::cout << "3) Salir" << std::endl;
        std::cin >> iselec;

        switch (iselec)
        {
        case 1:
            demoListasSimples();
            break;
        case 2:
            demoListasCirculares();
            break;
        default:
            break;
        }
    } while (iselec != 3);
    
    
    
}

void demoListasCirculares()
{
    std::cout << "Vamos a insertar en Circular" << std::endl;
    snodoCircularinicial = insertarListaC(10.5f, 45.5f, snodoCircularinicial);
    snodoCircularinicial = insertarListaC(20.5f, 30.5f, snodoCircularinicial);
    snodoCircularinicial = insertarListaC(10.5f, 40.5f, snodoCircularinicial);
    std::cout << "Imprimimos todos" << std::endl;
    imprimirListaC(snodoCircularinicial);
    std::cout << "-- FIN --" << std::endl;

    std::cout << "Digite cualquier tecla + enter para continuar" << std::endl;
    char enter;
    std::cin >> enter;
}

void demoListasSimples()
{
    std::cout << "Vamos a insertar" << std::endl;
    snodoinicial = insertarListaS(3.5f, 5.5f, snodoinicial);
    snodoinicial = insertarListaS(2.5f, 3.5f, snodoinicial);
    snodoinicial = insertarListaS(1.5f, 4.5f, snodoinicial);
    std::cout << "Imprimimos todos" << std::endl;
    imprimirListaSNormal(snodoinicial);
    std::cout << "Imprimimos desde el final" << std::endl;
    imprimirListaSinversa(snodoinicial);
    std::cout << "Buscamos el segundo" << std::endl;
    bool resultado;
    resultado = buscarVerticeLS(2.5f, 3.5f, snodoinicial);
    if (resultado)
        std::cout << "Lo encontramos" << std::endl;
    else
        std::cout << "No lo encontramos" << std::endl;
    std::cout << std::endl << std::endl;
    
    std::cout << "Digite cualquier tecla + enter para continuar" << std::endl;
    char enter;
    std::cin >> enter;

}