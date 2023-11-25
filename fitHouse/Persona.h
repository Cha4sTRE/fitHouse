#pragma once
#include<iostream>
class Persona
{
private:
	std::string _nombre;
	std::string _apellido;
	std::string _sexo;
	int _edad;
	int _cedula;
	int _telefono;

public:
	Persona(std::string nombre, std::string apellido, std::string sexo, int edad, int cedula, int telefono);

	inline std::string getNombre() { return _nombre; }
	inline std::string getApellido() { return _apellido; }
	inline std::string getSexo() { return _sexo; }
	inline int getEdad() { return _edad; }
	inline int getcedula() { return _cedula; }
	inline int getTelefono() { return _telefono; }

	inline void setNombre(std::string nombre) { _nombre = nombre; }
	inline void setApellido(std::string apellido) { _apellido = apellido; }
	inline void setEdad(int edad) { _edad = edad; }
	inline void setSexo(std::string sexo) { _sexo = sexo; }
	inline void setCedula(int cedula) { _cedula = cedula; }
	inline void setTelefono(int telefono) { _telefono = telefono; }
};

