#include <iostream>
#include <string>
using namespace std;
const int MAX_PRODUCTOS = 100;
const int MAX_VENTAS = 100;
struct Producto{
	string nombre;
	float precio;
};
struct Venta {
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;
};
int main() {
    Producto productos[MAX_PRODUCTOS];
    Venta ventas[MAX_VENTAS];
    int totalProductos = 0;
    int totalVentas = 0;
    char opcion;
    do {
    	cout << "\n----- MENU -----\n";
    	cout << "A: Registrar un nuevo producto\n";
    	cout << "B: Listar los productos registrados\n";
    	cout << "C: Buscar un producto por nombre\n";
    	cout << "D: Actualizar los datos de un producto\n";
    	cout << "E: Eliminar un producto\n";
        cout << "F: Registrar una venta\n";
        cout << "G: Listar las ventas realizadas\n";
        cout << "H: Calcular el total de ventas realizadas\n";
        cout << "S: Salir del programa\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion){
        	case 'A': {
        		if (totalProductos >= MAX_PRODUCTOS) {
        			cout << "No se pueden registrar mas productos.\n";
				break;
			}
			Producto b;
			cout << "Ingrese el nombre del producto: ";
			getline(cin, b.nombre);
			cout << "Ingrese el precio: ";
			cin >> b.precio;
			cin.ignore();
			productos[totalProductos] = b;
			totalProductos++;
			cout << "Producto registrado con exito.\n";
			break;		
		}
		
    }
        
	}
	
}
