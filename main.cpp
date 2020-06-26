#include <iostream>
#include "Archivo.h"
#include "Soldado.h"
#include "Soprte.h"
#include "Asalto.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu();
int main() {
	menu();
	return 0;
}
void simulacion(vector<Soldado*>,vector<Soldado*>);
void menu(){
	int op;
	int validc;
	Archivo* filesoprt = new Archivo("Soporte.bin");
	Archivo* fileasalt = new Archivo("Asalto.bin");
	vector<Soldado*>raiz;
	do{
		cout << "1.Crear soldado\n2.Eliminar soldados\n3.Listar soldados\n4.Guardar soldados\n5.Cargar soldados\n6.Simulación\n7.Salir\n:";
		cin >> op;
		switch(op){
			case 1:{
				if(validc !=0){
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
				}else{
					cout << "Cargue los archivos porvafor:)" << endl;
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
					op = 4;			
				}else{
					cout << "Cargue los soldados\n";
				}
	
				break;
			}
			case 3:{
				if(raiz.size() > 0){
					for(int i = 0 ; i < raiz.size() ; i++){
					   cout <<i<< "." << raiz[i]->getNombre()<< endl;
				   }
				}else{
					cout << "Cargue la lista" << endl;
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
				raiz.clear();
				fileasalt->CargarAsalto(raiz);
				filesoprt->CaragarSoporte(raiz);
				fileasalt->cerrarLectura();
				filesoprt->cerrarLectura();
				validc = 1;
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
			    simulacion(equipo1,equipo2);
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
void simulacion(vector<Soldado*> eqp1,vector<Soldado*>eqp2){
    
	
	bool valid =true;
	int cont = 0;
	srand(time(NULL));
	
	int s1 = eqp1.size()-1, s2 = eqp2.size()-1;
	int num,num2;
	while(valid){
		
		if(s1 != 0 ){
		 	num = 0 + rand() % (s1);
		}else{
			num = 0;
		}
		if(s2 != 0 ){
			num2 = 0 + rand() % (s2);
		}else{
			num2 = 0;
		}
		if(eqp1.size() > 0 && eqp2.size() > 0){
			if(cont%2 == 0){
				eqp2[num2]->Defensa(eqp1[num]->atacar(eqp2[num2]),eqp1[num]);
			}else{
				eqp1[num]->Defensa(eqp2[num2]->atacar(eqp1[num]),eqp2[num2]);
			}
			if(eqp1[num]->getPVida() <=0){
				eqp1.erase(eqp1.begin()+num);
			}
			if(eqp2[num2]->getPVida() <=0){
				eqp2.erase(eqp2.begin()+num2);
			}
		}
		if(eqp1.size() == 0){
			cout << "Gana equipo 2"<< endl;
			valid = false;
		}
		if(eqp2.size() ==0){
			cout << "Gana equipo 1"<< endl;
			valid = false;
		}
		cont++;
	}
}
