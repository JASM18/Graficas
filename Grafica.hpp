#ifndef GRAFICA_HPP
#define GRAFICA_HPP

#include <string>

using std::string;

//si intentamos agregar un vertice o una arista repetidos, no se agrega

//para eliminar, primero se birran las arisras y luego el nodo

class Grafica {
public:

    Grafica();
    ~Grafica();
    Grafica(const Grafica& grafica);
    Grafica& operator=(const Grafica& grafica);

    void AgregarNodo(string nombre);
    void AgregarArista(string origen, string destino);

    void EliminarNodo(string nombre);
    void EliminarArista(string origen, string destino);

    int ObtenerGradoDeNodo(string nombre) const;

    int ObtenerNumNodos() const;

    int ObtenerNumAristas() const;

    bool EstaVacia() const;

    bool EsConexo() const;

    void VaciarNodo(string nodo);

    void Vaciar();

    bool BuscarNodo(string nombre) const;

    bool BuscarArista(string origen, string destino) const;

    void Imprimir() const;

private:
    int numNodos;
    int numAristas;

    struct Arista;

    struct Nodo {

        string Nombre;
        int grado;

        Arista *primero;
        Arista *ultima;

        Nodo *siguiente;

        Nodo(string nom, Nodo *sig = nullptr);
    };

    struct Arista {

        Nodo *adyacente;

        Arista *siguiente;

        Arista(Nodo* ady, Arista* sig = nullptr);
    };

    Nodo *primero;
    Nodo *ultimo;

    Nodo* obtenerDireccDeUnNodo(string nombre) const;
};

#endif // GRAFICA_HPP
