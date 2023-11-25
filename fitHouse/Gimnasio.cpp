#include<iostream>
#include<string>
#include "Gimnasio.h"
#include"Usuario.h"
#include"funciones.h"

void Gimnasio:: mostrarUsuarios() {
	int opcion;
	int contador = 0;
	for (auto& usuario : _listaUsuarios) {
		std::cout << contador << "). " << usuario.getNombre() << " " << usuario.getApellido() << std::endl;
		contador += 1;
	}
	std::cout << ">>";
	std::cin >> opcion;

	if (_listaUsuarios.size() > 1) {
		system("cls");
		auto it = _listaUsuarios.begin();
		std::advance(it, opcion);
		std::cout << "nombre: " << it->getNombre() << " " << it->getApellido() << std::endl;
		std::cout << "sexo: " << it->getSexo() << std::endl;
		std::cout << "edad: " << it->getEdad() << std::endl;
		std::cout << "peso: " << it->getPeso() << std::endl;
		std::cout << "altura: " << it->getAltura() << std::endl;
		std::cout << "cedula: " << it->getcedula() << std::endl;
		std::cout << "telefono: " << it->getTelefono() << std::endl;
		std::cout << "\nIMS(Indice de masa corporal): "<<it->calcularIMS() << std::endl<<it->getNombre()<<" tiene ";

		it->calcularIMS() < 18.5? std::cout << "bajo peso\n"
		: it->calcularIMS() < 24.9? std::cout << "peso normal\n"
		: it->calcularIMS() < 29.9? std::cout << "sobrepeso\n"
		: it->calcularIMS() >= 30? std::cout << "obesidad\n"
		: std::cout << "valor de IMC no categorizado\n";

	}




}
void Gimnasio:: agregarUsuario(Usuario nuevoUsuario) {

	_listaUsuarios.push_back(nuevoUsuario);

}