/**

E-COMERCE - SITUACIÓN PROBLEMA.
Hecho por: Mónica Andrea Ayala Marrero - A01707439

Descripción: El programa simula una tienda virtual para la ficticia llamada "LA BOUTIQUE", el programa permite al usuario registrarse como cliente al proporcionar todos sus datos (incluyendo una forma de pago). Luego del registro el usuario puede relizar opciones en un menú: 
1. Modificar sus datos de cliente
2. Ver sus datos de cliente
3. Ver el catalogo + añadir productos al carrito
4. Ver el carrito + pagar
5. Salir


**/

//Importar las distintas clases que se usarán en el código
#include <iostream>
#include <locale>  
#include <string>  
#include "input.hpp"
#include "producto.h"
#include "cliente.h"
#include "catalogo.h"
#include "carrito.h"

using namespace std;

//Función que despliega el menú principal
void menu(){
  cout<<"\n -------------MENU--------------"<<endl;
  cout << "Elija el número de la acción que desee realizar \n";
    cout<<"1. Modificar sus datos de cliente\n";
    cout<<"2. Ver datos de cliente\n";
    cout<<"3. Ver el catalogo\n";
    cout<<"4. Ver carrito\n";
    cout<<"5. Salir\n";
}

//MAIN
int main() {  
  //crear el cliente
  cliente cliente_1;
  //crear el catalogo
  catalogo catalogo;

  //crear los productos a vender con sus nombres y precios
  producto vestido;
  vestido.crear("vestido rojo", 350);
  producto blusa;
  blusa.crear("blusa negra", 150);
  producto falda;
  falda.crear("falda a cuadros", 400);
  producto vestido2;
  vestido2.crear("vestido azul", 270);
  producto pantalon;
  pantalon.crear("jeans mezclilla", 600);

  //definir colores para cambiar el texto en el output
  #define RESET   "\033[0m"
  #define CYAN "\033[36m"
  #define YELLOW  "\033[93m"

  //agregar los productos al catalogo
  producto lista[5]={vestido,blusa,falda,vestido2,pantalon};
  for (int i=0;i<5;i++){
    catalogo.lista_catalogo[i]=lista[i];
  }

  //crear el carrito virtual donde el usuario puede añadir productos
  carrito carrito;

  //darle la bienvenida al cliente
  cout<<CYAN<<"\n------------------------------------------------"<<RESET<<endl;
  cout <<CYAN<< "BIENVENIDO A LA BOUTIQUE"<<RESET<<endl;
  cout<<CYAN<<"------------------------------------------------"<<RESET<<endl;

  //registrar los datos del cliente
  cout<<"Primero registrate como cliente:"<<endl;
  cliente_1.registrar(); 
 
  //crear el loop que va a correr el menu hasta que el cliente decida salir
  bool continua = true;
  int op;
  
  while (continua == true){
    menu(); //lamar a la función de menu()
    cin>>op; //pedir que el cliente ingrese la acción que desea

    if (op == 1){
      cliente_1.registrar(); //para cambiar sus datos ya registrados
    }
    else if (op==2){
      cliente_1.ver_info(); //para visualizar sus datos ya registrados
    }
    else if (op == 3){  
      catalogo.ver_catalogo(); //despliega el catalogo
      char k;
      bool seguir = true;
      cout<<"\nPresione el numero de producto que quiere añadir al carrito. Para regresar al menú presione 'm' "<<endl;
      while (seguir){
        k = getch(); //utiliza input.hpp para la función
		    switch(k){ //añade al carrito el producto que indique el usuario al presionar el numero correspondiente al producto
          case '1':
            std::cout <<YELLOW << "¡Agrego un vestido rojo!" << RESET << std::endl;
            carrito.agregar_producto(lista[0]);//añade al carrito
				    break;
			    case '2':
            cout<<YELLOW<<"¡Agrego una blusa!"<<RESET<<endl;
				    carrito.agregar_producto(lista[1]);//añade al carrito
				    break;
			    case '3':
            cout<<YELLOW<<"¡Agrego una falda a cuadros!"<<RESET<<endl;
				    carrito.agregar_producto(lista[2]);//añade al carrito
			    	break;
          case '4':
            cout<<YELLOW<<"¡Agrego un vestido azul!"<<RESET<<endl;
				    carrito.agregar_producto(lista[3]);//añade al carrito
				    break;
			    case '5':
            cout<<YELLOW<<"¡Agrego un jeans de mezclilla!"<<RESET<<endl;
				    carrito.agregar_producto(lista[4]);//añade al carrito
			    	break;
          case 'm':
				    seguir=false;
			    	break;
        }
      }
    }
    else if (op==4){
      carrito.pagar(cliente_1); //permite visualizar el carrito y decidir si pagar
    }
    else if (op==5){
      cout<<"Gracias por su preferencia"; //despedida 
      continua = false;
    }
  } 
  
  
}