#include <iostream>
#include "Grafica.hpp"

using namespace std;

int main()
{
    try {
        Grafica grafica;

        cout << "Agregando nodos: A, B, C, D, E" << endl;
        grafica.AgregarNodo("A");
        grafica.AgregarNodo("B");
        grafica.AgregarNodo("C");
        grafica.AgregarNodo("D");
        grafica.AgregarNodo("E");

        cout << "Unimos nodos" << endl;
        grafica.AgregarArista("A", "B");
        grafica.AgregarArista("A", "C");
        grafica.AgregarArista("C", "D");
        grafica.AgregarArista("D", "E");

        cout << "\nESTADO INICIAL:" << endl;
        grafica.Imprimir();

        cout << "Orden (n\243mero de Nodos): " << grafica.ObtenerNumNodos() << endl;
        cout << "Tama\244o (n\243mero de Aristas): " << grafica.ObtenerNumAristas() << endl;
        cout << "Grado del nodo C: " << grafica.ObtenerGradoDeNodo("C") << endl;
        cout << "Es conexa? (Todos se alcanzan): " << (grafica.EsConexo() ? "S\241" : "No") << endl;

        cout << "\nEliminando la conexi\242n entre C y D" << endl;
        grafica.EliminarArista("C", "D");

        grafica.Imprimir();
        cout << "Tama\244o actualizado: " << grafica.ObtenerNumAristas() << endl;
        cout << "Sigue siendo conexa?: " << (grafica.EsConexo() ? "S\241" : "No (Se partio en dos)") << endl;

        cout << "Eliminando el nodo A (esto deberia borrar sus aristas hacia B y C)" << endl;
        grafica.EliminarNodo("A");

        grafica.Imprimir();
        cout << "Orden actualizado: " << grafica.ObtenerNumNodos() << endl;

        cout << "Vaciando la grafica por completo..." << endl;
        grafica.Vaciar();
        grafica.Imprimir();

    } catch (const exception& e) {
        cerr << "Ocurri\242 un error: " << e.what() << endl;
    } catch (...) {
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    cout << "\nPrueba terminada. ";
    system("pause");
    return 0;
}
