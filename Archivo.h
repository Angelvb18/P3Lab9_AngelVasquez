#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Soldado.h"
#include "Soprte.h"
#include "Asalto.h"
#include <string>
#include <vector>
using std::vector;
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;
class Archivo
{
	public:
		Archivo(string);
		void GuardarAsalto(vector<Soldado*>lista);
		void GuardarSoporte(vector<Soldado*>lista);
		void CargarAsalto(vector<Soldado*>&);
		void CaragarSoporte(vector<Soldado*>&);
		bool abrirEscritura();
		bool abrirLectura();
		bool cerrarLectura();
		bool cerrarEscritura();
	protected:
		string fileName;
		ofstream outputFile;
		int modoEscritura;
		ifstream inputFile;
};

#endif
