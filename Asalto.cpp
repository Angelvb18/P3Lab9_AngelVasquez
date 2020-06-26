#include "Asalto.h"

Asalto::Asalto(string nombre,int fuerza,int vida,int velo,int extra):Soldado(nombre,fuerza,vida)
{
	velocidad = velo;
	fextra = extra;
}

Asalto::~Asalto()
{
}
void Asalto::setVelocidad(int v){
	velocidad = v;
}
void Asalto::setFextra(int f){
	fextra = f;
}
int Asalto::atacar(Soldado* atacado){
	if(dynamic_cast<Asalto*>(atacado)){
		return pFuerza*10;
	}else{
		return pFuerza*(10+(velocidad*2));
	}
}
void Asalto::Defensa(int ataque,Soldado* atacante){
	if(dynamic_cast<Asalto*>(atacante)){
		pVida = pVida-ataque;
	}else{
		pVida = pVida-(ataque/fextra);
	}
}
