#include <iostream>
using namespace std;

//CLASE cliente que almacena todos los datos del usuario
class cliente{
  public:
    string nombre;
    string telefono;
    string correo;
    string direccion;
    string num_tarjeta;
    string nombre_tarjeta;
    
    //registra los datos
    void registrar(){
      cout<<"\n-----------REGISTRO--------------"<<endl;
      string x;
      cout << "Ingresa tu nombre:";
      getline(cin, x);
      nombre=x;
      cout << "Ingresa tu telefono:";
      getline(cin, x);
      telefono = x;
      cout << "Ingresa tu correo:";
      getline(cin, x);
      correo = x;
      cout << "Ingresa tu direccion:";
      getline(cin, x);
      direccion = x;
      cout << "Ingresa tu numero de tarjeta (Solo VISA/Mastercard de 16 digitos):";
      getline(cin, x);
      //while para no dejar continuar hasta realizar la validacion de la tarjeta
      bool m=validar_tarjeta(x);
      while(m==0){
        cout << "Ingresa tu numero de tarjeta:";
        getline(cin, x);
        m=validar_tarjeta(x);
      }
      cout << "Ingresa tu nombre de tarjeta:";
      getline(cin, x);
      nombre_tarjeta=x;
    }
    //despliega la información ya registrada del cliente
    void ver_info(){
      cout<<"\n";
      cout << "---------INFO CLIENTE-----------"<<endl;
      cout << "nombre:" << nombre <<endl;
      cout << "telefono:" << telefono<<endl;
      cout << "correo:" << correo<<endl;
      cout << "dirección:" << direccion <<endl;
      cout << "número de tarjeta:" << num_tarjeta<<endl;
      cout << "nombre de tarjeta:" << nombre_tarjeta<<endl;
    }
    string getNombreTarjeta(){ //devuelve el nombre en la tarjeta
			return nombre_tarjeta;
		}
    string getNumTarjeta(){//devuelve el numero de tarjeta
			return num_tarjeta;
		}

    bool validar_tarjeta(string); //metodo de validacion
    
};

//metodo de validacion de tarjetas de 16 digitos VISA/MASTERCARD
//basado en el algoritmo de Luhn //https://www.geeksforgeeks.org/program-credit-card-number-validation/
bool cliente::validar_tarjeta(string num){
  int sum[8];
  int sum2[8];
  int k=0;
  int j=0;
  for (int i=0;i<16;i++){
    if (i%2==0){
      sum[j]=(num[i]-48)*2%10+(((num[i]-48)*2/10)%10)%10; //permite sumar los digitos cuando el numero tiene 2 digitos (i.e 18 = 1 + 8 = 9)
      j++;
    }
    else{
      sum2[k]=num[i]-48; //el -48 es para convertir de str a int
      k++;
    }
  }
  
  int suma=0; //suma los numeros de los arrays sum y sum2
  for (int i = 0; i < 8; i++) {
    suma=suma+sum[i]+sum2[i];
  }
  if (suma%10==0){
    cout<<"tarjeta valida"<<endl;
    return 1;
  }
  else{
    cout<<"tarjeta invalida"<<endl;
    return 0;
  }
  
}

