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
  Activo * act[MAX]; //es apuntador para que sea dinámico y usar polimorfismo
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
  double calcula_balance_anual();
};
void Club::muestra_activos() {
  //Ciclo que va imprimiendo cada elemento del arreglo
  for (int i = 0; i < infraestructura; i++)
    cout << act[i] -> to_string();
}
void Club::muestra_activos(string tipo_activo) {

  //Ciclo que va imprimiendo cada elemento del arreglo, con la condicion de que el tipo de activo sea el que le especificamos
  for (int i = 0; i < infraestructura; i++) {
    if (act[i] -> get_tipo_activo() == tipo_activo)
      cout << act[i] -> to_string();
  }
}
//se crea una funcion de agregar para cada tipo de empleado
void Club::agrega_jugador(string nombre, double salario_mensual) {
  act[infraestructura] = new Jugador(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_entrenador(string nombre, double salario_mensual) {
  act[infraestructura] = new Entrenador(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_oficinista(string nombre, double salario_mensual) {
  act[infraestructura] = new Oficinista(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_ejecutivo(string nombre, double salario_mensual) {
  act[infraestructura] = new Ejecutivo(infraestructura, nombre, salario_mensual);
  infraestructura++;
}
void Club::agrega_inmueble(string nombre, string localizacion, double costo_mensual_mantenimiento) {

  act[infraestructura] = new Inmueble(infraestructura, nombre, localizacion, costo_mensual_mantenimiento);
  infraestructura++;
}
void Club::agrega_patrocinio(string nombre, double valor_anual) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  act[infraestructura] = new Patrocinio(infraestructura, nombre, valor_anual);
  infraestructura++;
}
double Club::calcula_balance_anual() {
  double balance = 0;                //se va a ir acumulando la sumatoria a traves del ciclo for en esta variable
  Empleado *ep = NULL;
  Inmueble *ip = NULL;
  Patrocinio *pp = NULL;              //No apuntan a nada, hasta que les damos valor dentro de la estructura condicional
  for (int i = 0; i < infraestructura; i++) {
    if (act[i] -> get_tipo_activo() == "Empleado") {       //creamos un caso para cada clase hija de la clase activo
      ep = (Empleado*) act[i];                            //volvemos el apuntador de la clase padre a un apuntador de la clase hija
      balance -= ep -> pago_anual_con_bonus();
    }
    else if (act[i] -> get_tipo_activo() == "Inmueble"){
      ip = (Inmueble*) act[i];
      balance -= ip -> get_costo_mensual_mantenimiento()*12;
    }
    else if (act[i] -> get_tipo_activo() == "Patrocinio"){
      pp = (Patrocinio*) act[i];
      balance += pp -> get_valor_anual();
    }
  }
return balance;
}
#endif
