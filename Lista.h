#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //UTILICE COMO REFERENCIA LOS EJERCICIOS DESARROLLADOS EN CLASE
    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        //Este if evalue si inicio es igual a NULL, eso quiere decir que no hay ningun valor existente y, siendo asi, devuelve true
        if(inicio==NULL)
            return true;
        //de lo contrario devuelve false
        else
            return false;
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
        //aqui simplemente se devuelve el valor con el contenido del inicio
        return inicio->valor;
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        //Primero se crea una variables temporal con valor NULL
        Nodo<Tipo>*tempo = NULL;
        //este ciclo for recorrera la lista hatsa el final
        for(tempo = inicio; tempo->sig!=NULL; tempo = tempo->sig)
        {
        //    cout<<"Se recorre el Nodo"<<endl;
        }
        //se devuelve el ultimo valor que se encontro en el recorrido y que fue asignado a la variable temporal
        return tempo->valor;
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        //Primero se crea la variable vmayor que estara vacia
        Nodo<Tipo>*vmayor;
        //Luego se crea una variable temporal con valor NULL
        Nodo<Tipo>*tempo = NULL;
        //este ciclo for recorrera la lista hatsa el final
        for(tempo = inicio; tempo!=NULL; tempo = tempo->sig)
        {
            //en cada recorrido esta condicion evalua si vmayor es menor que la temporal y es asi la variable mayor se iguala a la temporal
            if(vmayor<tempo)
                vmayor=tempo;
        }
        //finalmente se devuelve el valor mayor encontrado
        return vmayor->valor;
    }
};
#endif // LISTA_H
