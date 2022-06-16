#include <iostream> //incuimos iostream para poder hacer uso de cout y cin
#include "club.h" //incluimos las bibliotecas que declaran los objetos
#include "activo.h"
using namespace std;
void menu(){
  cout << "Presione 1 para agregar empleado \n";
  cout << "Presione 2 para agregar inmueble \n";
  cout << "Presione 3 para agregar patrocinio \n";
  cout << "Presione 4 para mostrar activos de un tipo especifico \n";
  cout << "Presione 5 para mostrar todos los activos \n";
  cout << "Presione 6 para calcular el balance anual del club \n";
  cout << "Presione 7 para salir del programa \n";
}
//imprime un menu con las opciones que ofrece el programa
int main(){
  Club club;
  cout << "Base de datos del Club | Menu Principal\n"; //se imprime un menu con las opciones que tiene ofrece el programa
  menu();
  //declaramos las variables que se van a utilizar para el funcionamiento del menu (el uso de las funciones a traves de este
  //y los casos para los switches)
  int opcion; 
  string nombre_nuevo_empleado;
  double salario_nuevo_empleado;
  int opcion_tipo_nuevo_empleado;
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
        cout << "Tipo de empleado: \n";
        cout << "Presiona 1 si es jugador\n";
        cout << "Presiona 2 si es entrenador\n";
        cout << "Presiona 3 si es ejecutivo\n";
        cout << "Presiona 4 si es trabajador de oficina\n";
        cin >> opcion_tipo_nuevo_empleado;
        cout << "Nombre: \n";
        std::getline(std::cin >> ws, nombre_nuevo_empleado); //para que no haya problema al poner espacios
        cout << "Salario mensual: \n";
        cin >> salario_nuevo_empleado;
        switch (opcion_tipo_nuevo_empleado){
          case 1:
            club.agrega_jugador(nombre_nuevo_empleado, salario_nuevo_empleado);
          break;
          case 2:
            club.agrega_entrenador(nombre_nuevo_empleado, salario_nuevo_empleado);
          break;
          case 3:
            club.agrega_ejecutivo(nombre_nuevo_empleado, salario_nuevo_empleado);
          break;
          case 4:
            club.agrega_oficinista(nombre_nuevo_empleado, salario_nuevo_empleado);
          break;
          default:
            cout << "Invalido, ingrese una opcion existente\n";
            menu();
          break;
        }
        cout << "Empleado agregado\n";
        menu();
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
        menu();
        break;
      case 3:
        cout << "Agregando patrocinio\n";
        cout << "Marca: \n";
        std::getline(std::cin >> ws, marca_nuevo_patrocinio);
        cout << "Valor anual: \n";
        cin >> valor_nuevo_patrocinio;
        club.agrega_patrocinio(marca_nuevo_patrocinio, valor_nuevo_patrocinio);
        cout << "Patrocinio agregado\n";
        menu();
        break;
      case 4:
        cout << "Mostrar activos\n";
        cout << "Presione 1 para mostrar empleados\n";
        cout << "Presione 2 para mostrar inmuebles\n";
        cout << "Presione 3 para mostrar patrocinios\n";
        cin >> tipo_a_mostrar;
        switch (tipo_a_mostrar) {
          case 1:
            club.muestra_activos("Empleado");
          break;
          case 2:
            club.muestra_activos("Inmueble");
          break;
          case 3:
            club.muestra_activos("Patrocinio");
          break;
          default:
            cout << "Invalido, ingrese una opcion existente\n";
            menu();
          break;
        }
        menu();
        break;
      case 5:
        cout << "Mostrando todos los activos\n";
        club.muestra_activos();
        menu();
      break;
      case 6:
        cout << "Balance anual del club: ";
        cout << club.calcula_balance_anual() << " dolares. \n";
        menu();
       break;
      case 7:
        cout << "Programa cerrado\n";
        trabajando = !trabajando;
        break;
      default:
        cout << "Invalido, ingrese una opcion existente\n";
        menu();
        break;
    }
  }
}
