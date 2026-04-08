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
    if(BuscarNodo(nombre)) return;

    try{
        Nodo *nuevo = new Nodo(nombre);
        nuevo->grado = 0;
        nuevo->primero = nullptr;
        nuevo->ultima = nullptr;
        nuevo->siguiente = nullptr;

        if(EstaVacia()){
            primero = nuevo;
            ultimo = nuevo;
        }else{
            ultimo->siguiente = nuevo;
            ultimo = nuevo;

        }

        ++numNodos;
    }catch(std::bad_alloc&){
        //throw EXCEPCION
    }
}

//***********************************

void Grafica::AgregarArista(string origen, string destino)
{
    // Condiciones:
    // 1. Eviar ciclos (que el origen sea igual al destino)
    // 2. Que la arista que se desee construir ya exista
    // 3. que el nombre de origen o destino no exista

    if(origen == destino) return; // se evitan ciclos

    if(BuscarArista(origen, destino)) return; // Ya existe la arista

    Nodo *nodoOrigen = obtenerDireccDeUnNodo(origen);
    Nodo *nodoDestino = obtenerDireccDeUnNodo(destino);


    if(nodoOrigen == nullptr || nodoDestino == nullptr) return; // Alguno de los dos nodos no existe

    // Se cumplen todas las condiciones para que la arista exista
    // -> Crear la conexion del origen al destino y del destino al origen

    try{
        Arista* nuevaAristaOrigDest = new Arista(nodoDestino);

        if(nodoOrigen->primero == nullptr){ // No hay aristas!

            nodoOrigen->primero = nuevaAristaOrigDest;
            nodoOrigen->ultima = nuevaAristaOrigDest;
        }else{
            nodoOrigen->ultima->siguiente = nuevaAristaOrigDest;
            nodoOrigen->ultima = nuevaAristaOrigDest;
        }

        ++nodoOrigen->grado;

        Arista* nuevaAristaDestOrig = new Arista(nodoOrigen);

        if(nodoDestino->primero == nullptr){ // No hay aristas!

            nodoDestino->primero = nuevaAristaDestOrig;
            nodoDestino->ultima = nuevaAristaDestOrig;
        }else{
            nodoDestino->ultima->siguiente = nuevaAristaDestOrig;
            nodoDestino->ultima = nuevaAristaDestOrig;
        }

        ++nodoDestino->grado;
        ++numAristas;
    }catch(const std::bad_alloc&){
        //throw EXCEPCION
    }
}

//***********************************

bool Grafica::EliminarNodo(string nombre)
{

}

//***********************************

bool Grafica::EliminarArista(string origen, string destino)
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
    return obtenerDireccDeUnNodo(nombre) != nullptr;
}

//***********************************

bool Grafica::BuscarArista(string origen, string destino) const
{
    Nodo *nodoOrigen = obtenerDireccDeUnNodo(origen); // Encontramos la direccion del nodo de origen

    if(nodoOrigen == nullptr) return false;

    Arista* aristaVisitada = nodoOrigen->primero; // Puntero para checar todas sus aristas

    while(aristaVisitada != nullptr){

        if(aristaVisitada->adyacente->Nombre == destino){ // Si el nombre del nodo que conecta la arista es igual al nombre del destino, significa que se encontro la arista deseada
            return true;
        }
        aristaVisitada = aristaVisitada->siguiente;
    }

    return false;
}

//***********************************

void Grafica::Imprimir() const
{

}

//***********************************
// EXCEPCIONES
//***********************************

Grafica::GraficaNoMemoria::GraficaNoMemoria() throw() {}

//***********************************

const char *Grafica::GraficaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
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

    while(visitado != nullptr){ // Se recorre toda la lista de nodos en el grafo

        if(visitado->Nombre == nombre) return visitado; // Si el nodo que visitamos, su nombre es igual al nombre que buscamos, regresamos su direccion
        visitado = visitado->siguiente;
    }

    return nullptr;
}
