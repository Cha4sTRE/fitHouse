#include"funciones.h"
#include"Usuario.h"

#include<string>

std::string interfaz1() {
	std::string entrada;
	system("cls");
	std::cout << "[a]crear nuevo codigo\ncodigo de seguridad: ";
	getline(std::cin, entrada);
	return entrada;
}
int interfaz2() {
	int entrada;
	std::cout << "\nopcines: \n";
	std::cout << "1. ver usuarios\n";
	std::cout << "2. salir\n";
	std::cin >> entrada;
	return entrada;
}
Usuario nuevoRegistro() {
	char opcion;
	std::cout << "agregar usuario: "; std::cin >> opcion;
	if (opcion == 'y' || opcion == 'Y') {

		Usuario nuevo;
		std::string nombre, apellido, sexo;
		int edad, cedula, telefono;
		float peso, altura;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");
		std::cout << "||  registro de usuarios  ||";
		std::cout << "\nnombre: "; std::getline(std::cin, nombre); nuevo.setNombre(nombre);
		std::cout << "apellido: "; std::getline(std::cin, apellido); nuevo.setApellido(apellido);
		std::cout << "sexo: "; std::getline(std::cin, sexo); nuevo.setSexo(sexo);
		std::cout << "edad: "; std::cin >> edad; nuevo.setEdad(edad);
		std::cout << "cedula: "; std::cin >> cedula; nuevo.setCedula(cedula);
		std::cout << "telefono: "; std::cin >> telefono; nuevo.setTelefono(telefono);
		std::cout << "peso: "; std::cin >> peso; nuevo.setPeso(peso);
		std::cout << "altura: "; std::cin >> altura; nuevo.setAltura(altura);

		return nuevo;
	}
	else {
		return Usuario();
	}

}