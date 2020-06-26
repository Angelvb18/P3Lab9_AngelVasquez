#ifndef ASALTO_H
#define ASALTO_H

#include "Soldado.h"
#include "Soprte.h"
class Archivo;
class Asalto : public Soldado
{
	public:
		Asalto(string,int,int,int,int);
		~Asalto();
		int getVelocidad(){return velocidad;}
		int getFextra(){return fextra;}
		void setVelocidad(int);
		void setFextra(int);
		int atacar(Soldado*);
		void Defensa(int,Soldado*);
	protected:
		int velocidad,fextra;
		friend class Archivo;

};

#endif
