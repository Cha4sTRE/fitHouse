#include <iostream>
#include <string>
#include<fstream>
#include<conio.h>
#include"funciones.h"

std::string generarCodigo(std::string codigo) {

	system("cls");
	std::string ruta = "C://Users//chaus//Desktop//fesc//segundo semestre//p. estructurada//codigos.txt";
	std::string nuevoCodigo;
	std::cout << "introdusca la nueva clave: ";
	getline(std::cin, nuevoCodigo);
	if (nuevoCodigo == codigo) {
		std::cout << "la contraseña es la misma";
		_getch();
		interfaz1();
	}
	else {
		std::ofstream archivo;
		archivo.open(ruta, std::ios::out);
		if (archivo.fail()) { std::exit(1); }
		archivo << nuevoCodigo<<std::endl;
		archivo.close();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return nuevoCodigo;

}