#include<iostream>
#include<string>
#include "Gimnasio.h"
#include"Usuario.h"
#include"funciones.h"

int posicion;
int Gimnasio:: mostrarUsuarios() {
	char opcion;
	int contador = 0;

	auto it = _listaUsuarios.begin();
	system("cls");
	for (auto& usuario : _listaUsuarios) {
		std::cout << contador << "). " << usuario.getNombre() << " " << usuario.getApellido() << std::endl;
		contador++;
	}
	std::cout << "agregar usuario [1] si [2] no :"; std::cin >> opcion;
	if (opcion != '1'||opcion=='\n') {
	std::cout << "usuario: "; std::cin >> posicion;
	if (_listaUsuarios.size() > 1) {
		
		system("cls");
		std::advance(it, posicion);
		std::cout << "nombre: " << it->getNombre() << " " << it->getApellido() << std::endl;
		std::cout << "sexo: " << it->getSexo() << std::endl;
		std::cout << "edad: " << it->getEdad() << std::endl;
		std::cout << "peso: " << it->getPeso() << std::endl;
		std::cout << "altura: " << it->getAltura() << std::endl;
		std::cout << "cedula: " << it->getcedula() << std::endl;
		std::cout << "telefono: " << it->getTelefono() << std::endl;
		std::cout << "fecha de registro: " << it->getFechaCreacion();

		std::cout << "\nIMS(Indice de masa corporal): "<<it->calcularIMS() << std::endl<<it->getNombre()<<" tiene ";
		it->calcularIMS() < 18.5? std::cout << "bajo peso\n"
		: it->calcularIMS() < 24.9? std::cout << "peso normal\n"
		: it->calcularIMS() < 29.9? std::cout << "sobrepeso\n"
		: it->calcularIMS() >= 30? std::cout << "obesidad\n"
		: std::cout << "valor de IMC no categorizado\n";
		it->generarFactura();
		std::cout << "\n[2] editar\n[3] eliminar";
		std::cout << ">>";
		std::cin >> opcion;

	}
	}
	return opcion;

}
void Gimnasio:: agregarUsuario(Usuario nuevoUsuario) {
	_listaUsuarios.push_back(nuevoUsuario);
}
void Gimnasio::eliminarUsuario() {
	auto it = _listaUsuarios.begin();
	std::advance(it, posicion);
	_listaUsuarios.erase(it);
}
void Gimnasio::editarUsuario() {
	system("cls");
	auto it = _listaUsuarios.begin();
	std::string nombre, apellido, sexo;
	int edad, cedula, telefono;
	float peso, altura;

	std::advance(it, posicion);
	std::cout<< "||  editar a " << it->getNombre() << "   ||"<<std::endl;

	std::cout << "Nombre: "; std::getline(std::cin >> std::ws, nombre); it->setNombre(nombre);
	std::cout << "Apellido: "; std::getline(std::cin >> std::ws, apellido); it->setApellido(apellido);
	std::cout << "Sexo: "; std::getline(std::cin >> std::ws, sexo); it->setSexo(sexo);

	std::cout << "edad: "; std::cin >> edad; it->setEdad(edad);
	std::cout << "cedula: "; std::cin >> cedula; it->setCedula(cedula);
	std::cout << "telefono: "; std::cin >> telefono; it->setTelefono(telefono);
	std::cout << "peso: "; std::cin >> peso; it->setPeso(peso);
	std::cout << "altura: "; std::cin >> altura; it->setAltura(altura);
}