#ifndef ACTIVO_H_
#define ACTIVO_H_

#include <string>

#include <sstream>

using namespace std;

class Activo {
//declaramos las variables de instancia, como protegidas
private:
  int id;
  string nombre;
  string tipo_activo;
//métodos serán públicos
public:
  Activo(): id(0), nombre(""), tipo_activo("") {}; //constructor default
Activo(int id_num, string nom, string tipo_a):
  id(id_num), nombre(nom), tipo_activo(tipo_a) {};
//getters
  double get_id() {
    return id;
  }
  string get_nombre() {
    return nombre;
  }
  string get_tipo_activo() {
    return tipo_activo;
  }
    virtual string to_string() = 0; // es método abstacto que se reescribirá dependiendo la subclase 
};
//Declaramos objeto empleado que hereda de Activo
class Empleado: public Activo  {
private:
  double salario_mensual;
  string tipo_empleado;
public:
  Empleado(): Activo(0, "","Empleado"){};
 Empleado(int id, string nombre, double salar, string tipo_e): Activo(id, nombre, "Empleado"),
 salario_mensual(salar), tipo_empleado(tipo_e) {};
 int get_id() {
   return id;
  }
  string get_nombre() {
    return nombre;
  }
  virtual double pago_anual_con_bonus() = 0;
  //es abstracta ya que no se va a usar en esta clase padre
  string get_tipo_empleado() {
    return tipo_empleado;
   }
    string to_string();
  //convierte el objeto en string y le agrega el formato para ser impreso

};
string Empleado::to_string() {

  stringstream aux;
  aux << "ID: " << id << " . Activo del tipo: " << tipo_activo << ". Nombre: " << nombre <<
  ". Tipo de empleado: " << tipo_empleado << ". Salario mensual: " << salario_mensual << " dolares. \n";
   return aux.str();

}
//Declaramos objeto inmueble que hereda de Activo
class Inmueble: public Activo {
private:
  string localizacion;
  double costo_mensual_mantenimiento;
public:
  Inmueble(): Activo(0, "", "Inmueble"){};
Inmueble(int id, string nombre, string local, double costo_m_m): Activo(id, nombre, "Inmueble"),
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
  aux << "ID: " << id << ". Activo del tipo: " << tipo_activo << ". Es el inmueble llamado " << nombre << " . Ubicado en " << localizacion <<
    ". Costo mensual de mantenimiento: " << costo_mensual_mantenimiento << " dolares.\n";
  return aux.str();
}
class Patrocinio: public Activo{
private:
  double valor_anual;
public:
  Patrocinio(): Activo(0, "", "Patrocinio"){};
Patrocinio(int id, string nombre, double valor_a): Activo(id, nombre, "Patrocinio"),
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
  aux << "ID: " << id << ". Activo del tipo: " << tipo_activo << ", de la marca " << nombre <<
    ", con un valor anual de " << valor_anual << " dolares. \n";
  return aux.str();
}
//subclases de empleado que no tienen ningun atributo nuevo
class Jugador: public Empleado {
public:
  Jugador(): Empleado(0, "", 0, "Jugador"){};
 Jugador(int id, string nombre, double salar): Empleado(id, nombre, salar, "Jugador") {};
  double pago_anual_con_bonus() {
    return salario_mensual*12.15;
//la funcion se sobreescribe en cada subclase para reflejar el bonus especifico a cada tipo de empleado
  }
};
class Entrenador: public Empleado {
public:
  Entrenador(): Empleado(0, "", 0, "Entrenador"){};
 Entrenador(int id, string nombre, double salar): Empleado(id, nombre, salar, "Entrenador") {};
  double pago_anual_con_bonus() {
    return salario_mensual*12.1;
  }
};
class Ejecutivo: public Empleado {
public:
  Ejecutivo(): Empleado(0, "", 0, "Ejecutivo"){};
 Ejecutivo(int id, string nombre, double salar): Empleado(id, nombre, salar, "Ejecutivo") {};
  double pago_anual_con_bonus() {
    return salario_mensual*12.25; //ejecutivos
  }
};
class Oficinista: public Empleado {
public:
  Oficinista(): Empleado(0, "", 0, "Oficinista"){};
 Oficinista(int id, string nombre, double salar): Empleado(id, nombre, salar, "Oficinista") {};
  double pago_anual_con_bonus() {
    return salario_mensual*12.05;
  }
};
#endif
