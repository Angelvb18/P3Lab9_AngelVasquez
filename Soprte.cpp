#include "Soprte.h"
#include "Asalto.h"
Soprte::Soprte(string nombre,int fuerza,int vida,int blin,int cam):Soldado(nombre,fuerza,vida)
{
	blindaje = blin;
	camuflaje = cam;
}

Soprte::~Soprte()
{
}
void Soprte::setBlindaje(int b){
	blindaje = b;
}
void Soprte::setCamuflaje(int a){
   camuflaje = a;
}
int Soprte::atacar(Soldado* atacado){
	if(dynamic_cast<Asalto*>(atacado)){
		return pFuerza*(15+camuflaje);
	}else{
		return pFuerza*10;
	}
}
void Soprte::Defensa(int ataque,Soldado* atacante){
	if(dynamic_cast<Asalto*>(atacante)){
		pVida = pVida-(ataque/(blindaje*2));
	}else{
		pVida = pVida-ataque;
	}
}
