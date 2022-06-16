#ifndef ITEM_H_
#define ITEM_H_

#include <string>

#include <sstream>

using namespace std;

class Item {
//declaramos las variables de instancia, como protegidas
protected:
  int id;
  string nombre;
  string tipo_item;
//métodos serán públicos
public:
  Item(): id(0), nombre(""), tipo_item("") {}; //constructor default
Item(int id_num, string nom, string tipo_i):
  id(id_num), nombre(nom), tipo_item(tipo_i) {};
//getters
  double get_id() {
    return id;
  }
  string get_nombre() {
    return nombre;
  }
  string get_tipo_item() {
    return tipo_item;
  }
    virtual string to_string() = 0; // es método abstacto que se reescribirá dependiendo la subclase 

};
//Declaramos objeto empleado que hereda de Item
class Empleado: public Item  {
protected:
  double salario_mensual;
  string tipo_empleado;
public:
  Empleado(): Item(0, "","Empleado"){};
 Empleado(int id, string nombre, double salar, string tipo_e): Item(id, nombre, "Empleado"),
 salario_mensual(salar), tipo_empleado(tipo_e) {};
 int get_id() {
   return id;
  }
  string get_nombre() {
    return nombre;
  }
  double pago_mensual() {
    return salario_mensual;
  }
  string get_tipo_empleado() {
    return tipo_empleado;
   }
    string to_string();
  //convierte el objeto en string y le agrega el formato para ser impreso

};
string Empleado::to_string() {

  stringstream aux;
  aux << "ID: " << id << " . Activo del tipo: " << tipo_item << ". Nombre: " << nombre <<
  ". Tipo de empleado: " << tipo_empleado << ". Salario mensual: " << salario_mensual << " dolares. \n";
   return aux.str();

}
//Declaramos objeto inmueble que hereda de Item
class Inmueble: public Item {
protected:
  string localizacion;
  double costo_mensual_mantenimiento;
public:
  Inmueble(): Item(0, "", "Inmueble"){};
Inmueble(int id, string nombre, string local, double costo_m_m): Item(id, nombre, "Inmueble"),
localizacion(local), costo_mensual_mantenimiento(costo_m_m) {};
  int get_id() {
   return id;
  }
  string get_nombre() {
    return nombre;
  }
  string get_localizacion() {
    return localizacion;
  }
  double get_costo_mensual_mantenimiento() {
    return costo_mensual_mantenimiento;
    }
    string to_string();
//convierte el objeto en string y le agrega el formato para ser impreso
};
string Inmueble::to_string() {

  stringstream aux;
  aux << "ID: " << id << ". Activo del tipo: " << tipo_item << ". Es el inmueble llamado " << nombre <<
    ". Costo mensual de mantenimiento: " << costo_mensual_mantenimiento << " dolares.\n";
  return aux.str();
}
class Patrocinio: public Item{
protected:
  double valor_anual;
public:
  Patrocinio(): Item(0, "", "Patrocinio"){};
Patrocinio(int id, string nombre, double valor_a): Item(id, nombre, "Patrocinio"),
valor_anual(valor_a){};
int get_id() {
 return id;
}
string get_nombre() {
  return nombre;
}
double get_valor_anual(){
  return valor_anual;
}
string to_string();
};
string Patrocinio::to_string() {

  stringstream aux;
  aux << "ID: " << id << ". Activo del tipo: " << tipo_item << ", de la marca " << nombre <<
    ", con un valor anual de " << valor_anual << " dolares. \n";
  return aux.str();
}
class Jugador: public Empleado {
public:
  double pago_anual_con_bonus() {
    return salario_mensual*12.15;
//la funcion se sobreescribe en cada subclase para reflejar el bonus especifico a cada tipo de empleado
  }
};
class Entrenador: public Empleado {
public:
  double pago_anual_con_bonus() {
    return salario_mensual*12.1;
  }
};
class Ejecutivo: public Empleado {
public:
  double pago_anual_con_bonus() {
    return salario_mensual*12.25; //ejecutivos
  }
};
class Oficinista: public Empleado {
public:
  double pago_anual_con_bonus() {
    return salario_mensual*12.05;
  }
};
#endif
