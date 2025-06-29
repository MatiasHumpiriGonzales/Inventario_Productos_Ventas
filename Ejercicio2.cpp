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
		   case 'B': {
		   	if (totalProductos == 0){
		   		cout << "No hay productos registrados.\n";
			   } else {
			   	cout << "\n ___ Lista de productos ___\n";
			   	for (int i = 0; i < totalProductos; i++) {
			   		cout << "Prodcuto " << (i + 1) << ":\n";
			   		cout << "Nombre: " << productos[i].nombre << endl;
			   		cout << "Precio: S/ " << productos[i].precio << endl;
			   		cout << "__________________________________\n";
				   }
			   }
			break;
		   }
		   case 'C' :{
		   	if (totalProductos == 0) {
		   		cout << "No hay productos registrados para buscar.\n";
		   		break;
			   }
			   string nombreBuscar;
			   cout << "Ingrese el nombre del producto a buscar: ";
			   getline(cin, nombreBuscar);
			   bool encontrado = false;
			   for (int i = 0;i < totalProductos; i++) {
			   	if (productos[i].nombre == nombreBuscar) {
			   		cout << "Producto encontrado:\n";
			   		cout << "Nombre: " << productos[i].nombre << endl;
			   		cout << "Precio: S/ " << productos[i].precio << endl;
			   		encontrado = true;
			   		break;
				   }
			   }
			   if (!encontrado) {
			   	cout << "Producto no encontrado.\n";
			   }
			break;
		   }
		   case 'D': {
		   	if (totalProductos == 0) {
		   		cout << "No hay productos para actualizar.\n";
		   		break;
			   }
			   string nombreBuscar;
			   cout << "Ingrese el nombre del producto a actualizar: ";
			   getline(cin, nombreBuscar);
			   bool actualizado = false;
			   for (int i= 0; i< totalProductos; i++){
			   	if(productos[i].nombre == nombreBuscar){
			   		cout << "Producto encontrado.\n";
			   		cout << "Nombre actual: " << productos[i].nombre << endl;
			   		cout << "Precio actual: S/ " << productos[i].precio << endl;
			   		cout << "Ingrese el nuevo nombre: ";
			   		getline(cin, productos[i].nombre);
			   		cout << "Ingrese el nuevo precio: ";
			   		cin >> productos[i].precio;
					cin.ignore();
					cout << "Producto actualizado correctamente.\n";
					actualizado = true;
					break;
				   }
			   }
			   if (!actualizado) {
			   	cout << "Producto no encontrado.\n";
			   }
			break;
		   }
		   case 'E': {
		   	if (totalProductos == 0) {
		   		cout << "No hay productos para eliminar.\n";
		   		break;
			   }
			   string nombreEliminar;
			   cout << "Ingrese el nombre del producto a eliminar: ";
			   getline(cin, nombreEliminar);
			   bool eliminado = false;
			   for (int i = 0;i < totalProductos; i++){
			   	if (productos[i].nombre == nombreEliminar){
			   		 for (int j= i; j < totalProductos - 1; j--){
			   		 	productos[j] = productos[j+1];
						}
						totalProductos--;
						eliminado = true;
						cout << "Producto eliminado correctamente.\n";
						break;
				   }
			   }
			   if (!eliminado){
			   	cout << "Producto no encontrado.\n";
			   }
			break;
		   }
		   case 'F': {
		   	if (totalProductos == 0){
		   		cout << "No hay productos para vender.\n";;
		   		break;
			   }
			   if (totalVentas >= MAX_VENTAS){
			   	cout << "No se pueden registrar mas ventas.\n";
			   	break;
			   }
			   string nombreProducto;
			   cout << "Ingrese el nombre del producto a vender: ";
			   getline(cin, nombreProducto);
			   int indiceProducto = -1;
			   for (int i = 0; i < totalProductos; i++){
			   	if (productos[i].nombre == nombreProducto) {
			   		indiceProducto = 1;
			   		break;
				   }
			   }
			   int cantidadVendida;
			   cout << "Ingrese la cantidad vendida: ";
			   cin >> cantidadVendida;
			   cin.ignore();
			   Venta c;
			   c.idVenta = totalVentas + 1;
			   c.producto = productos[indiceProducto].nombre;
			   c.cantidad = cantidadVendida;
			   c.precioTotal = cantidadVendida * productos[indiceProducto].precio;
			   ventas[totalVentas] = c;
			   totalVentas++;
			   cout << "Venta registrada correctamente.\n";
			break;
		   }
		   
		   
		   
		  
    }
        
	}
	
}
