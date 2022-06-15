#include <iostream> //incuimos iostream para poder hacer uso de cout y cin
#include "club.h" //incluimos las bibliotecas que declaran los objetos
#include "item.h"
using namespace std;
int main(){
  Club club;
  cout << "Base de datos del Club | Menu Principal\n"; //se imprime un menu con las opciones que tiene ofrece el programa
  cout << "Presione 1 para agregar empleado \n";
  cout << "Presione 2 para agregar inmueble \n";
  cout << "Presione 3 para agregar patrocinio \n";
  cout << "Presione 4 para mostrar items \n";
  cout << "Presione 5 para salir del programa \n";
  //declaramos las variables que se van a utilizar para el funcionamiento del menu (el uso de las funciones a traves de este)
  int opcion; 
  string nombre_nuevo_empleado;
  double salario_nuevo_empleado;
  string tipo_nuevo_empleado;
  string nombre_nuevo_inmueble;
  string localizacion_nuevo_inmueble;
  double mantenimiento_nuevo_inmueble;
  string marca_nuevo_patrocinio;
  double valor_nuevo_patrocinio;
  int tipo_a_mostrar;
  bool trabajando = true; 
  while (trabajando) {
    cin >> opcion;
    switch (opcion) {
      case 1:
        cout << "Agregando empleado\n";
        cout << "Nombre: \n";
        std::getline(std::cin >> ws, nombre_nuevo_empleado);
        cout << "Salario mensual: \n";
        cin >> salario_nuevo_empleado;
        cout << "Tipo de empleado: \n";
        cin >> tipo_nuevo_empleado;
        club.agrega_empleado(nombre_nuevo_empleado, salario_nuevo_empleado, tipo_nuevo_empleado);
        cout << "Empleado agregado\n";
        cout << "Ingrese una nueva opcion\n";
        break;
      case 2:
        cout << "Agregando inmueble\n";
        cout << "Nombre: \n";
        std::getline(std::cin >> ws, nombre_nuevo_inmueble);
        cout << "Localizacion: \n";
        std::getline(std::cin >> ws, localizacion_nuevo_inmueble);
        cout << "Costo mantenimiento mensual: \n";
        cin >> mantenimiento_nuevo_inmueble;
        club.agrega_inmueble(nombre_nuevo_inmueble, localizacion_nuevo_inmueble, mantenimiento_nuevo_inmueble);
        cout << "Inmueble agregado\n";
        cout << "Ingrese una nueva opcion\n";
        break;
      case 3:
        cout << "Agregando patrocinio\n";
        cout << "Marca: \n";
        std::getline(std::cin >> ws, marca_nuevo_patrocinio);
        cout << "Valor anual: \n";
        cin >> valor_nuevo_patrocinio;
        club.agrega_patrocinio(marca_nuevo_patrocinio, valor_nuevo_patrocinio);
        cout << "Patrocinio agregado\n";
        cout << "Ingrese una nueva opcion\n";
        break;
      case 4:
        cout << "Mostrar items\n";
        cout << "Presione 1 para mostrar empleados\n";
        cout << "Presione 2 para mostrar inmuebles\n";
        cout << "Presione 3 para mostrar patrocinios\n";
        cin >> tipo_a_mostrar;
        switch (tipo_a_mostrar) {
          case 1:
            club.muestra_items("Empleado");
          break;
          case 2:
            club.muestra_items("Inmueble");
          break;
          case 3:
            club.muestra_items("Patrocinio");
          break;
          default:
            cout << "Invalido, ingrese una opcion existente\n";
          break;
        }
        cout << "Ingrese una nueva opcion\n";
        break;
      case 5:
        cout << "Programa cerrado\n";
        trabajando = !trabajando;
        break;
      default:
        cout << "Invalido, ingrese una opcion existente\n";
        break;
    }
  }
}
