#include <iostream>
#include "Item.h"
using namespace std;
int main(){
  Club club;
  club.crea_ejemplos();
  club.muestra_items();
  cout<<"test \n\n";
  club.muestra_items("Inmueble");
  club.agrega_empleado("Neymar", 150000.2);
  club.muestra_items("Empleado");
  club.agrega_inmueble("Complejo oficinas 2", "Calle Alfredo Talavera 455", 460.5);
  club.muestra_items("Inmueble");
  cout << "test \n\n";
}
