#pragma once
#include<iostream>
#include<string>
#include"Persona.h"
class Usuario: public Persona
{
protected:
	float _peso;
	float _altura;
	std::string _plan;
	std::string _condicionMedica;
	std::string _rutina;
	std::string _historial;
public:
	Usuario();
	Usuario(std::string nombre, std::string apellido, std::string sexo, int edad, int cedula, int telefono,
		float peso, float altura, std::string plan, std::string condicionMedica, std::string rutina, std::string historial);

	float calcularIMS();
	inline float getPeso() { return _peso; }
	inline float getAltura() { return _altura; }
	inline void setPeso(float peso) { _peso = peso; }
	inline void setAltura(float altura) { _altura = altura; }

};

