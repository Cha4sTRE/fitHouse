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
	std::string _plan;
	std::string _condicionMedica;
	std::string _rutina;
	std::string _historial;
	std::chrono::system_clock::time_point fechaCreacion;
public:
	Usuario();
	Usuario(std::string nombre, std::string apellido, std::string sexo, int edad, int cedula, int telefono,
		float peso, float altura, std::string plan, std::string condicionMedica, std::string rutina, std::string historial);

	float calcularIMS();
	inline float getPeso() { return _peso; }
	inline float getAltura() { return _altura; }
	inline std::string getFechaCreacion(){
		std::time_t tiempo = std::chrono::system_clock::to_time_t(fechaCreacion);
		// Estructura tm para obtener una representación más controlada del tiempo
		std::tm tiempoStruct;
		localtime_s(&tiempoStruct, &tiempo);
		// Crear una cadena con el formato deseado
		char buffer[20];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tiempoStruct);
		return std::string(buffer);
	}
	inline void setPeso(float peso) { _peso = peso; }
	inline void setAltura(float altura) { _altura = altura; }

};

