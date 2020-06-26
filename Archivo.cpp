#include "Archivo.h"
#include <iostream>
using std::cout ;
Archivo::Archivo(string fileName){
	this->fileName = fileName;
}
void Archivo::GuardarAsalto(vector<Soldado*>lista){
	if(outputFile.is_open()){
		for(int i = 0 ; i < lista.size() ; i++){
			
			if(dynamic_cast<Asalto*>(lista[i])){
				
				int sizeNombre = lista[i]->getNombre().size();
				outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
				
				outputFile.write(lista[i]->getNombre().data(),sizeNombre);
				
				outputFile.write(reinterpret_cast<char*>(&lista[i]->pVida), (int)sizeof(int) );
				outputFile.write(reinterpret_cast<char*>(&lista[i]->pFuerza), (int)sizeof(int) );
				
				outputFile.write(reinterpret_cast<char*>(&dynamic_cast<Asalto*>(lista[i])->velocidad), (int)sizeof(int) );
				outputFile.write(reinterpret_cast<char*>(&dynamic_cast<Asalto*>(lista[i])->fextra), (int)sizeof(int) );
			}
		}
	}
}

void Archivo::GuardarSoporte(vector<Soldado*>lista){
	if(outputFile.is_open()){
		for(int i = 0 ; i < lista.size() ; i++){
			if(dynamic_cast<Soprte*>(lista[i])){
				int sizeNombre = lista[i]->getNombre().size();
				outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
				outputFile.write(lista[i]->getNombre().data(),sizeNombre);
				outputFile.write(reinterpret_cast<char*>(&lista[i]->pVida), (int)sizeof(int) );
				outputFile.write(reinterpret_cast<char*>(&lista[i]->pFuerza), (int)sizeof(int) );
				outputFile.write(reinterpret_cast<char*>(&dynamic_cast<Soprte*>(lista[i])->blindaje), (int)sizeof(int) );
				outputFile.write(reinterpret_cast<char*>(&dynamic_cast<Soprte*>(lista[i])->camuflaje), (int)sizeof(int) );
			}
		}
	}
}
void Archivo::CargarAsalto(vector<Soldado*>& lista){
	while(!inputFile.eof()){
	  	int nameSize=0;
	  	int vida=0;
	  	int fuerza=0;
	  	int velocidad=0;
	  	int fextra=0;
	  	inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
	  	char name[100];
	  	inputFile.read(name,nameSize);		 	
	 	string nombre(name,nameSize);
	  	inputFile.read(reinterpret_cast<char*>(&vida),sizeof(int));
	  	inputFile.read(reinterpret_cast<char*>(&fuerza),sizeof(int));
	  	inputFile.read(reinterpret_cast<char*>(&velocidad),sizeof(int));
	  	inputFile.read(reinterpret_cast<char*>(&fextra),sizeof(int));
	  	if(nombre.size() > 0){
	  		Soldado* a = new Asalto(nombre,fuerza,vida,velocidad,fextra);
			lista.push_back(a);
		}

	}
}
void Archivo::CaragarSoporte(vector<Soldado*>& lista){
	while(!inputFile.eof()){
	  	int nameSize=0;
	  	int vida=0;
	  	int fuerza=0;
	  	int blindaje=0;
	  	int camuflaje=0;
	  	inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
	  	char name[100];
	  	inputFile.read(name,nameSize);		 	
	 	string nombre(name,nameSize);
	  	inputFile.read(reinterpret_cast<char*>(&vida),sizeof(int));
	  	inputFile.read(reinterpret_cast<char*>(&fuerza),sizeof(int));
	  	inputFile.read(reinterpret_cast<char*>(&blindaje),sizeof(int));
	  	inputFile.read(reinterpret_cast<char*>(&camuflaje),sizeof(int));
	  	if(nombre.size() > 0){
	  		lista.push_back(new Soprte(nombre,fuerza,vida,blindaje,camuflaje));
		}
		
	}
}
bool Archivo::abrirEscritura(){
	outputFile.open(fileName.c_str(), std::ios::binary);		
	return outputFile.is_open();
}
bool Archivo::abrirLectura(){
	inputFile.open(fileName.c_str(),std::ios::binary);
	return inputFile.is_open();
}
 bool Archivo::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}	
bool Archivo::cerrarLectura(){
	inputFile.close();
	return !inputFile.is_open();
}
