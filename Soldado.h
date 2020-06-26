#ifndef SOLDADO_H
#define SOLDADO_H
#include <iostream>
using std::string;
class Archivo;
class Soldado
{
	public:
		Soldado(string,int,int);
		~Soldado();
		string getNombre(){return nombre;}
		int getPVida(){return pVida;}
		int getPFuerza(){return pFuerza;}
		void setFuerza(int);
		void setVida(int);
		virtual int atacar(Soldado*) = 0;
		virtual void Defensa(int,Soldado*)=0;
	protected:
		string nombre;
		int pVida,pFuerza;
		friend class Archivo;
};

#endif
