#ifndef GRAFICA_HPP
#define GRAFICA_HPP

#include <string>
#include <exception>

using std::string;

//si intentamos agregar un vertice o una arista repetidos, no se agrega

//para eliminar, primero se birran las arisras y luego el nodo

class Grafica {
public:

    Grafica();
    ~Grafica();
    Grafica(const Grafica& grafica);
    Grafica& operator=(const Grafica& grafica);

    void AgregarNodo(string nombre); // LISTO
    void AgregarArista(string origen, string destino); // LISTO

    bool EliminarNodo(string nombre);
    bool EliminarArista(string origen, string destino);

    int ObtenerGradoDeNodo(string nombre) const;
    int ObtenerNumNodos() const; // LISTO
    int ObtenerNumAristas() const; // LISTO

    bool EstaVacia() const; // LISTO

    bool EsConexo() const;

    void VaciarNodo(string nodo);
    void Vaciar();

    bool BuscarNodo(string nombre) const; // LISTO
    bool BuscarArista(string origen, string destino) const; // LISTO

    void Imprimir() const;


    class GraficaNoMemoria : public std::exception {
    public:
//        /** \brief Constructor por default de la excepci&oacute;n ColaVacia.
//         */
        GraficaNoMemoria() throw();

//        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una lista vac&iacute;a.
//         *
//         * \return Cadena de caracteres con el mensaje de error.
//         */
        virtual const char *what() const throw();
    };

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

    Nodo* obtenerDireccDeUnNodo(string nombre) const; // LISTO
};

#endif // GRAFICA_HPP
