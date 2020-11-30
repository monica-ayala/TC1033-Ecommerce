#include <iostream>
using namespace std;
//CLASE carrito

class carrito{
  
  public:
    int total;
    string lista_productos[100]; //permite almacenar hasta 100 productos
    int lista_precios[100]; 
    int tamaño; //tamaño del carrito
    void pagar(cliente); 
    void agregar_producto(producto producto);
    carrito(); //constructor
    void vaciar();
};

carrito :: carrito(){ //inicializa la lista
  for (int i=0; i<100; i++){
    lista_productos[i]="";
    lista_precios[i]=0;
  }
  tamaño=0;
  total=0;
}

//metodo para añadir un producto al carrito 
void carrito :: agregar_producto(producto p){
  lista_productos[tamaño]=p.nombre;
  lista_precios[tamaño]=p.precio;
  tamaño = tamaño + 1;

}

//metodo para vaciar al carrito
void carrito::vaciar(){
  for (int i=0; i<100; i++){
    lista_productos[i]="";
    lista_precios[i]=0;
  }
  tamaño=0;
  total=0;
}

//metodo para desplegar el carrito y proceder al pago
void carrito :: pagar(cliente x){
  cout<<"-------CARRITO-----------\n";
  for (int i=0; i<tamaño; i++){
    cout<<lista_productos[i]<<"--"<<lista_precios[i]<<"MXN"<<endl;
    total = total + lista_precios[i];
  }
  cout<<"Tu total:"<<total<<"MXN"<<endl;
  cout<<"\n1. Vaciar carrito";
  cout<<"\n2. Pagar";
  cout<<"\n3. Volver al menú";
  char op;
  cin>>op;
  if (op=='1'){
    vaciar();
  }
  else if (op=='2'){
    cout<<"Nombre de tarjeta:"<<x.getNombreTarjeta()<<endl; //verifica con que tarjeta estas pagando
    cout<<"Numero de tarjeta:"<<x.getNumTarjeta()<<endl;
    cout<<"¿Confirma la transacción? S/N"<<endl;
    cin>>op;
    if(op=='1'){
      cout<<"Se ha realizado el cargo por "<<total<<"MXN"<<endl;
    }
  }


}