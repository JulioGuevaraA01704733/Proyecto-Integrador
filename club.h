#ifndef CLUB_H_
#define CLUB_H_

#include <string>

#include <iostream>

#include <sstream>

#include "item.h" //biblioteca con mis objetos a usar

using namespace std;

const int MAX = 1000; //una constante que define el número máximo de elementos en los arreglos a utilizar
class Club {
  private:
  Item * it[MAX]; //es apuntador para que sea dinámico y usar polimorfismo
  int infraestructura;
  //declaramos constructor y otros métodos
  public:
  Club(): infraestructura(0) {}; //constructor por default
  void crea_ejemplos();
  void muestra_empleados();
  void muestra_items(string tipo_item);
  void agrega_empleado(string nombre, double salario_mensual);
  void agrega_inmueble(string nombre, string localizacion, double costo_mensual_mantenimiento);
};

void Club::crea_ejemplos() {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[infraestructura] = new Empleado(infraestructura, "Messi", 200000);
  nomina++;
  emp[infraestructura] = new Empleado(infraestructura, "El Bicho", 200000);
  nomina++;
  emp[infraestructura] = new Inmueble(infraestructura, "Estadio", "Boulevard Checo Pérez 511", 1000);
  nomina++;
  emp[infraestructura] = new Inmueble(infraestructura, "Complejo oficinas 1", "Calle Martin Luther King Jr 323", 500.5);
  nomina++;
}
void Club::muestra_items() {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < infraestructura; i++)
    cout << it[i] -> to_string();
}
void Club::muestra_items(string tipo_item) {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < infraestructura; i++) {
    if (it[i] -> get_tipo_item() == tipo_item)
      cout << it[i] -> to_string();
  }
}
void Club::agrega_empleado(string nombre, double salario_mensual) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  it[infraestructura] = new Empleado(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_inmueble(string nombre, double salario_mensual) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  it[infraestructura] = new Inmueble(string nombre, string localizacion, double costo_mensual_mantenimiento);
  infraestructura++;
}
#endif
