#include "Usuario.h"

//constructor por defecto -> inicializa objetos sin pasarle atributos inmediatamente
Usuario::Usuario() : Persona("", "", "", 0, 0, 0) {
	_peso = 0.0f;
	_altura = 0.0f;
	
}

Usuario::Usuario(std::string nombre, std::string apellido, std::string sexo, int edad, int cedula, int telefono,
	float peso, float altura,std::string plan, std::string condicionMedica, std::string rutina, std::string historial) :

	Persona(nombre, apellido, sexo, edad, cedula, telefono),
	_peso(peso),
	_altura(altura),
	_plan(plan),
	_condicionMedica(condicionMedica),
	_rutina(rutina),
	_historial(historial)

{}

float Usuario::calcularIMS() {
	float indice = (_peso / (_altura * _altura));
	return indice;
}
