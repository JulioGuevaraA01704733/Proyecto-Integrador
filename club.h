#ifndef CLUB_H_
#define CLUB_H_

#include <string>

#include <iostream>

#include <sstream>

#include "activo.h" //biblioteca que declara los objetos a usar

using namespace std;

const int MAX = 1000; //una constante que define el número máximo de elementos en los arreglos a utilizar
class Club { 
  private:
  Activo * it[MAX]; //es apuntador para que sea dinámico y usar polimorfismo
  int infraestructura;
  //declaramos constructor y otros métodos
  public:
  Club(): infraestructura(0) {}; //constructor por default
  void muestra_activos();
  void muestra_activos(string tipo_activo);
  //se crea una funcion de agregar para cada tipo de empleado
  void agrega_jugador(string nombre, double salario_mensual);
  void agrega_entrenador(string nombre, double salario_mensual);
  void agrega_oficinista(string nombre, double salario_mensual);
  void agrega_ejecutivo(string nombre, double salario_mensual);
  void agrega_inmueble(string nombre, string localizacion, double costo_mensual_mantenimiento);
  void agrega_patrocinio(string nombre, double valor_anual);
};
void Club::muestra_activos() {
  //Ciclo que va imprimiendo cada elemento del arreglo
  for (int i = 0; i < infraestructura; i++)
    cout << it[i] -> to_string();
}
void Club::muestra_activos(string tipo_activo) {

  //Ciclo que va imprimiendo cada elemento del arreglo
  for (int i = 0; i < infraestructura; i++) {
    if (it[i] -> get_tipo_activo() == tipo_activo)
      cout << it[i] -> to_string();
  }
}
//se crea una funcion de agregar para cada tipo de empleado
void Club::agrega_jugador(string nombre, double salario_mensual) {
  it[infraestructura] = new Jugador(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_entrenador(string nombre, double salario_mensual) {
  it[infraestructura] = new Entrenador(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_oficinista(string nombre, double salario_mensual) {
  it[infraestructura] = new Oficinista(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_ejecutivo(string nombre, double salario_mensual) {
  it[infraestructura] = new Ejecutivo(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_inmueble(string nombre, string localizacion, double costo_mensual_mantenimiento) {

  it[infraestructura] = new Inmueble(infraestructura, nombre, localizacion, costo_mensual_mantenimiento);
  infraestructura++;
}
void Club::agrega_patrocinio(string nombre, double valor_anual) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  it[infraestructura] = new Patrocinio(infraestructura, nombre, valor_anual);
  infraestructura++;
}
#endif
