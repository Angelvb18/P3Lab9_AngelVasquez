#include <iostream>
#include "Archivo.h"
#include "Soldado.h"
#include "Soprte.h"
#include "Asalto.h"
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu();
int main() {
	menu();
	return 0;
}
void menu(){
	int op;
	Archivo* filesoprt = new Archivo("Soporte.bin");
	Archivo* fileasalt = new Archivo("Asalto.bin");
	vector<Soldado*>raiz;
	do{
		cout << "1.Crear soldado\n2.Eliminar soldados\n3.Listar soldados\n4.Guardar soldados\n5.Cargar soldados\n6.Simulación\n7.Salir\n:";
		cin >> op;
		switch(op){
			case 1:{
				int op2;
				string nombre;
				int  vida,fuerza,extra1,extra2;
				cout << "1.Asalto\n2.Soporte\n:";
				cin >> op2;
				switch(op2){
					case 1:{
						cout << "Ingrese nombre:";
						cin >> nombre;
						cout << "Fuerza:";
						cin >> fuerza;
						cout << "Vida:";
						cin>> vida;
						cout << "Velocidad:";
						cin >> extra1;
						cout << "Fuerza Extra;";
						cin >> extra2;
						raiz.push_back(new Asalto(nombre,fuerza,vida,extra1,extra2));
						break;
					}
					case 2:{
						cout << "Ingrese nombre:";
						cin >> nombre;
						cout << "Fuerza:";
						cin >> fuerza;
						cout << "Vida:";
						cin>> vida;
						cout << "Blindaje:";
						cin >> extra1;
						cout << "Camuflaje:";
						cin >> extra2;
						raiz.push_back(new Soprte(nombre,fuerza,vida,extra1,extra2));
						break;
					}
					default :{
						cout << "No valido" << endl;
						break;
					}
				}
				break;
			}
			case 2:{
				if(raiz.size() > 0){
					int po;
					for(int i = 0 ; i < raiz.size() ; i++){
						cout <<i<< "." << raiz[i]->getNombre() << endl;
					}
					do{
						cout << "Ingrese numero de soldado:";
						cin >> po;
					}while(po > raiz.size()-1 || po< 0 );
					raiz.erase(raiz.begin()+po);			
				}else{
					cout << "Cargue los soldados\n";
				}
	
				break;
			}
			case 3:{
				for(int i = 0 ; i < raiz.size() ; i++){
					cout <<i<< "." << raiz[i]->getNombre()<< endl;
				}
				break;
			}
			case 4:{
				fileasalt->abrirEscritura();
				fileasalt->GuardarAsalto(raiz);
				fileasalt->cerrarEscritura();
				filesoprt->abrirEscritura();
				filesoprt->GuardarSoporte(raiz);
				filesoprt->cerrarEscritura();
				break;
			}
			case 5:{
				fileasalt->abrirLectura();
				filesoprt->abrirLectura();
				fileasalt->CargarAsalto(raiz);
				filesoprt->CaragarSoporte(raiz);
				fileasalt->cerrarLectura();
				filesoprt->cerrarLectura();
				break;
			}
			case 6:{
				vector<Soldado*>equipo1;
				vector<Soldado*>equipo2;
				for(int i = 0 ; i < raiz.size() ; i++){
					if(i %2 == 0){
						equipo1.push_back(raiz[i]);
					}else{
						equipo2.push_back(raiz[i]);
					}
				}
				
				break;
			}
			case 7:{
				cout << "Adios" << endl;
				break;
			}
			default:{
				cout << "Opcion no valida" <<endl;
				break;
			}
		}
	}while(op != 7);
}
