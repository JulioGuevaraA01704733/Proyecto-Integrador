#ifndef ITEM_H_
#define ITEM_H_

#include <string>

#include <sstream>

using namespace std;

class Item {
protected:
  string nombre;
  double valor;
  string tipo_item;

public:
  Item(): nombre(""), valor(0), tipo_item("") {};
Item(string nom, double val, string tipi):
  nombre(nom), valor(val),tipo_item(tipi) {};

  string get_nombre() {
    return nombre;
  }
  double get_valor() {
    return valor;
  }
  string get_tipo_item() {
    return tipo_item;
  }
};

class Empleado: public Item  {
protected:
  double salario_mensual;
  string tipo_empleado;
public:
  Empleado(): Item("", 0,"Empleado"){};
  Empleado(string nombre, double valor, double salar, string tipo_e): Item(nombre, valor, "Empleado"),
  salario_mensual(salar), tipo_empleado(tipo_e){};
  string get_nombre() {
    return nombre;
  }
  double get_valor() {
    return valor;
  }
  virtual double pago_mensual() = 0;
  virtual string to_string() = 0;
  
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
