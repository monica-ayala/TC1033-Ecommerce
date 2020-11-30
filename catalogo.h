#include <iostream>
using namespace std;
//CLASSE catalogo 
class catalogo {
  public:
   int tamaño=5; //restringe por ahora el tamaño del catalogo
   producto lista_catalogo[100]; //lista para tener productos 
   void ver_catalogo(){ //permite visualizar el catalogo con productos
     cout<<"---------CATALOGO---------\n";
     for (int i=0;i<tamaño;i++){
       cout<<i+1<<". "<<lista_catalogo[i].nombre<<"--"<<lista_catalogo[i].precio<<"MXN"<<endl;
     }
   }
   
};

