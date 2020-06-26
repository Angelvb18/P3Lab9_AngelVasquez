#include "Soldado.h"
Soldado::Soldado(string n,int f,int v){
	nombre = n;
	pFuerza = f;
	pVida = v;
}
Soldado::~Soldado(){
}
void Soldado::setFuerza(int f){
	pFuerza = f;
}
void Soldado::setVida(int v){
	pVida = v;
}
