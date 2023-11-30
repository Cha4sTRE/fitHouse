#pragma once
#include<iostream>
#include<string>
#include<chrono>
#include"Persona.h"
class Usuario: public Persona
{
protected:
	float _peso;
	float _altura;
	std::string _plan="mensual";
	std::string _condicionMedica;
	std::string _rutina;
	std::string _historial;
	std::chrono::system_clock::time_point _fechaCreacion;
public:
	Usuario();
	Usuario(std::string nombre, std::string apellido, std::string sexo, int edad, int cedula, int telefono,
		float peso, float altura, std::string plan, std::string condicionMedica, std::string rutina, std::string historial);

	float calcularIMS();
	inline float getPeso() { return _peso; }
	inline float getAltura() { return _altura; }
	inline std::string getPlan() { return _plan; }
	inline void setPeso(float peso) { _peso = peso; }
	inline void setAltura(float altura) { _altura = altura; }
	inline std::string getFechaCreacion() {
		
		std::time_t tiempo = std::chrono::system_clock::to_time_t(_fechaCreacion);
		std::tm tiempoStruct;
		localtime_s(&tiempoStruct, &tiempo);
		char buffer[20];
		strftime(buffer, sizeof(buffer), "%d/%m/%Y", &tiempoStruct);
		return std::string(buffer);
	}

	void generarFactura();

};

