#ifndef SOPRTE_H
#define SOPRTE_H

#include "Soldado.h"
class Archivo;
class Soprte : public Soldado
{
	public:
		Soprte(string,int,int,int,int);
		~Soprte();
		int getBlindaje(){return blindaje;}
		int getCamuflaje(){return camuflaje;}		
		void setBlindaje(int);
		void setCamuflaje(int);
		int atacar(Soldado*);
		void Defensa(int,Soldado*);
	protected:
		int blindaje,camuflaje;
		friend class Archivo;
};

#endif
