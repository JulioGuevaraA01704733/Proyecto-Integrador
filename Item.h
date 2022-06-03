#ifndef ITEM_H_
#define ITEM_H_

#include <string>

#include <sstream>

using namespace std;

class Item {
//declaramos las variables de instancia, como protegidas
protected:
  double valor;
  string nombre;
  string tipo_item;
//métodos serán públicos
public:
  Item(): valor(0), nombre(""), tipo_item("") {}; //constructor default
Item(double val, string nom, string tipo_i):
  valor(val), nombre(nom), tipo_item(tipo_i) {};
//getters
  double get_valor() {
    return valor;
  }
  string get_nombre() {
    return nombre;
  }
  string get_tipo_item() {
    return tipo_item;
  }
};
//Declaramos objeto empleado que hereda de Item
class Empleado: public Item  {
protected:
  double salario_mensual;
  string tipo_empleado;
public:
  Empleado(): Item(0, "","Empleado"){};
 Empleado(double valor, string nombre, double salar, string tipo_e): Item(valor, nombre, "Empleado"),
 salario_mensual(salar), tipo_empleado(tipo_e) {};
 double get_valor() {
   return valor;
  }
  string get_nombre() {
    return nombre;
  }
  double pago_mensual() {
    return salario_mensual;
  }
};

class Jugador: public Empleado  {
private:
  string posicion;
public:
  Jugador(): Empleado("", 0,"Empleado",0,"Jugador") {};
  Empleado(string nombre, double valor, double salar, string tipo_e, string pos): Empleado(nombre, valor, "Empleado", salario_mensual, "Jugador"),
  posicion(pos){};
  string get_nombre() {
    return nombre;
  }
  double get_valor() {
    return valor;
  }
  double pago_mensual() {
    return salario_mensual*1.5;
  }
  string to_string();
};
class Entrenador: public Empleado  {
private:
  string especialidad;
public:
  Entrenador(): Empleado("",0,"Empleado",0,"Entrenador"){};
  Empleado(string nombre, double valor, double salar, string tipo_e, string esp): Empleado(nombre, valor, "Empleado", salario_mensual, "Entrenador"),
  especialidad(esp){};
  string get_nombre() {
    return nombre;
  }
  double get_valor() {
    return valor;
  }
  double pago_mensual() {
    return salario_mensual*1.25;
  }
  string to_string();
};
#endif
