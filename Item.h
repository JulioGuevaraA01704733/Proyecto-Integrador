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
#endif
