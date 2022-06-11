#include <iostream> //incuimos iostream para poder hacer uso de cout y cin
#include "club.h" //incluimos las bibliotecas que declaran los objetos
#include "item.h"
using namespace std;
int main(){
  Club club;
  club.crea_ejemplos();
  club.muestra_items();
  club.muestra_items("Inmueble");
  club.agrega_empleado("Neymar", 150000.2, "Jugador");
  club.muestra_items("Empleado");
  club.agrega_inmueble("Complejo oficinas 2", "Calle Alfredo Talavera 455", 460.5);
  club.muestra_items("Inmueble");
  club.agrega_patrocinio("Coca Cola", 5000000);
  club.muestra_items("Patrocinio");
}
