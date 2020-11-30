#include <iostream>
using namespace std;

//CLASE producto, permite crear productos con precio y nombre
class producto{
  public:
  int precio;
  string nombre;
  void crear(string x, int y){ //se pudo haber hecho en un constructor pero enviaba error en la clase de CARRITO y la de CATALOGO que usan objetos de tipo producto
    precio=y;
    nombre=x;
  }
};

