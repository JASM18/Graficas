#include "Grafica.hpp"

//***********************************
// CONSTRUCTORES
//***********************************

Grafica::Grafica()
{
    numAristas = 0;
    numNodos = 0;

    primero = nullptr;
    ultimo = nullptr;
}

//***********************************

Grafica::~Grafica()
{
    Vaciar();
}

//***********************************

Grafica::Grafica(const Grafica& grafica)
{

}

//***********************************

Grafica& Grafica::operator=(const Grafica& grafica)
{
    if (this == &grafica) return *this;


    return *this;
}

//***********************************
// MÉTODOS PUBLICOS
//***********************************

void Grafica::AgregarNodo(string nombre)
{

}

//***********************************

void Grafica::AgregarArista(string origen, string destino)
{

}

//***********************************

void Grafica::EliminarNodo(string nombre)
{

}

//***********************************

void Grafica::EliminarArista(string origen, string destino)
{

}

//***********************************

int Grafica::ObtenerGradoDeNodo(string nombre) const
{

}

//***********************************

int Grafica::ObtenerNumNodos() const
{
    return numNodos;
}

//***********************************

int Grafica::ObtenerNumAristas() const
{
    return numAristas;
}

//***********************************

bool Grafica::EstaVacia() const
{
    return primero == nullptr;
}

//***********************************

bool Grafica::EsConexo() const
{

}

//***********************************

void Grafica::VaciarNodo(string nodo)
{

}

//***********************************

void Grafica::Vaciar()
{

}

//***********************************

bool Grafica::BuscarNodo(string nombre) const
{

}

//***********************************

bool Grafica::BuscarArista(string origen, string destino) const
{

}

//***********************************

void Grafica::Imprimir() const
{

}

//***********************************
// CONSTRUCTORES DE CLASES AUXILIARES
//***********************************

Grafica::Nodo::Nodo(string nom, Nodo *sig /*= nullptr*/) : Nombre(nom), siguiente(sig) {};

//***********************************

Grafica::Arista::Arista(Nodo* ady, Arista* sig /*= nullptr*/) : adyacente(ady), siguiente(sig) {};

//***********************************
// Métodos privados de la clase
//***********************************

Grafica::Nodo* Grafica::obtenerDireccDeUnNodo(string nombre) const
{
    Nodo* visitado = primero;

    while(visitado != nullptr){
        if(visitado->Nombre == nombre) return visitado;
        visitado = visitado->siguiente;
    }
    return nullptr;
}
