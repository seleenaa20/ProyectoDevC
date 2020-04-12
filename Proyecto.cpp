#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>           //Usamos las diferentes bibliotecas que usa el proyecto
void escribir();             //Declaramos la función escribir
void leer();                //Declaramos la funcion leer
void annadir();               //Declaramos la funcion añadir

using namespace std; 

class Champu{               //En POO hemos decidido que nuestro objeto va a ser el champu y definimos la clase champu
	private: 
		int litros;           //En modo privado definimos los atributos de litros y la marca del champu
		string marca;
	public: 
	 Champu(int, string); 
	 void mostrarCapacidad();               //En modo publico definimos los metodos de mostrar la capacidad y los ingredientes que compone el champu
	 void mostrarIngredientes();
};
Champu::Champu (int _litros, string _marca){ 
	litros = _litros; marca = _marca;             //En esta parte solo igualamos los atributos
}
void Champu :: mostrarCapacidad(){
	cout<< "La capacidad es: "<<endl;          //Declaramos la funcion mostrar la capacidad del envase del champu y nos los muestra en pantalla
}
void Champu :: mostrarIngredientes(){
	cout<< "Los ingedientes son: "<<endl;        //Declaramos la funcion mostrar los ingedientes con los que se ha hecho el champu
}

int main(){                  //Funcion principal
	string loreal;                    //Declaramos el atributo de la marca Loreal. 
	Champu n1= Champu(1,loreal);            //Definimos los litros y la marca del objeto
	n1.mostrarCapacidad(); n1.mostrarIngredientes();
	
	int numero;
	do{
		cout<< "\n";
		cout<< "------------------LISTA DE LA COMPRA------------------" << endl;
		cout<< "------- 1.- Crear una lista de la compra.    ---------" << endl;
		cout<< "------- 2.- Leer la lista de la copra        ---------" << endl;
		cout<< "------- 3.- Añadir productos a la lista      ---------" << endl;
		cout<< "------- 4.- Salir                            ---------" << endl;
		cout<< "------------------------------------------------------" << endl;            //Menu de nuestra lista e la compra para seleccionar una opción que quieres realizar, nos aparecera en pantalla
		cout<< "Selecciona una opcion: ";
		cin>> numero;                                                 //Elegimos la opción que queremos realizar poniendo el numero de la opción
		cin.ignore(256, '\n');
		
		switch(numero){                    //Depende del numero que eligamos, cada uno tiene una función declarada anteriormente. 
			case 1: escribir();
				break;
			case 2: leer();
				break;
			case 3: annadir();
				break;
			case 4: cout<< "Adios!"<< endl;
				break;
			default: cout << "\nEsa opcion no esta en el menu!!\n";        //nos indica que el numero que hemos elegido no es una de las opciones ha realizar. 
				break;
		}
	} while(numero!=4);      //Cuando la elegida es el 4 nos salimos de la pantalla
	system("pause");        
	return 0;
}
void escribir(){                 //Funcion escribir
	ofstream archivo;
	string nombreArchivo;
	string linea;
	int productos;              //dentro de esta funcion delaramos los propios atributos de ella con dos string y un int. Para saber el nombre del archivo que quieres crear

	cout<< "Nombre de la lista que quieres crear: ";               //Nos pregunta en pantalla el nombre del archivo que queremos crear
	getline(cin, nombreArchivo);                               //Dentro del ordenador crea el archivo
	archivo.open(nombreArchivo.c_str(), ios::out);
	
	if(archivo.fail()){                                   //Si el nombre del archivo no le corresponde, nos indicara que el archivo no se puede abrir
		cout<< "No puede abrir el archivo";
		exit(1); 
	}
	cout << "¿Cuantos productos quieres escribir en la lista? ";           //Si el archivo es correcto, nos preguntara cuantos productos queremos añadir a ese archivo o a esa lista donde les guardara
	cin >> productos;
	for(int i; i<=productos; i++){                                                 //Definimos el atributo i para indicar los diferentes productos que vamos señalando 
		cout << "Introduce los productos a escribir en el archivo..."<< endl; 
		getline(cin, linea); 
		archivo << linea << endl;                        //Linea significa que escribimos cada producto de la lista en diferentes lineas o apartados. 
	}
	archivo.close();                   //Cuando realizamos todos las "tareas" el archivo se cierra automaticamente
}
void leer(){                         //funcion leer archivo
	ifstream archivo; 
	string nombreArchivo;                  //Declaramos los propios atributos de la funcion lectura
	string linea; 
	cout << "Nombre de la lista que quieres leer: "; 
	getline(cin, nombreArchivo);                              //Nos indica que archivo queremos leer para abrirle una vez encontrado
	archivo.open(nombreArchivo.c_str(),ios::in); 
	cout<<nombreArchivo<<endl;
	if (archivo.fail()){                               //Si el nombre del archivo no corresponde con el que hemos creado no podremos abrirle porque no existe y nos indicara error
		cout<< "No se puede abrir la lista"; 
		exit(1); 
	}
	while (!archivo.eof()){
		getline(archivo, linea);                    //Por otro lado si corresponde, le abrira, nos aparecerá en pantalla y le podremos leer. 
		cout << linea<< endl; 
	}
	archivo.close();                 //Una vez realizadas las tareas cierra el archivo automaticamente
}
void annadir(){                   //Funcion añadir en el archivo
	ofstream archivo; 
	string nombreArchivo;               //Declaramos los propios atributos de la funcion añadir
	string linea; 
	int productos;
	cout<< "Nombre de la lista que quieres crear: ";                //Creamos un nuevo archivo donde podremos añadir mas productos
	getline(cin, nombreArchivo); 
	archivo.open(nombreArchivo.c_str(),ios::app); 
	if (archivo.fail()){                                        //Si el archivo nos corresponde, de nuevo, nos indicara en pantalla error al abrir el archivo
		cout<< "No puedo abrir la lista: "; 
		exit (1); 
	} 

	cout << "¿Cuantos productos quieres escribir en la lista? ";            //Por el contrario nos indicara cauntos productos u objetos queremos añadir a nuestra lista
	cin >> productos;
	for(int i; i<=productos; i++){                                  //Indicamos los diferentes productos a ñadir con el atributo i. 
		cout << "Ha escribir en la lista... "<< endl; 
		getline(cin, linea);                                     //Los diferentes productos se escribiran en diferentes lineas ya que es una lista. 
		archivo << linea << endl;
	}

	getline(cin, linea); 
	archivo << linea << endl;                      //una vez realizadas todas las tareas, el archivo se cerrara automaticamente. 
	archivo.close();
}

