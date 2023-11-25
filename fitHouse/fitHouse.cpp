#include <iostream>
#include<string>
#include<list>
#include<conio.h>

#include"funciones.h"
#include"Gimnasio.h"
#include"Usuario.h"


std::string codigo= "12345";
Gimnasio fitHouse;
int main()
{
//usuarios por defecto
Usuario john("john","Doe","hombre",0,0,0,0,0,"0","0","0","0");
Usuario jeffer("Jefferson","chaustre","hombre",19,1092524589,31668846822,60.6,1.69,"mensual","deficiencia motora","sentadilla","delincuente");
Usuario dilan("Dilan", "Bautista", "hombre", 18,65,65, 2234, 23535, "mensual", "sida", "peso muerto", "le gusta el pipi");
fitHouse.agregarUsuario(john);
fitHouse.agregarUsuario(jeffer);
fitHouse.agregarUsuario(dilan);

while (true) {
	if (interfaz1() == codigo) {
		std::cout << "bienvenido a la herramiento de gestion de clientes";
		_getch();
		while (true) {
			
			if (interfaz2()== 1) {
				fitHouse.mostrarUsuarios();
				fitHouse.agregarUsuario(nuevoRegistro());
			}
			else if (interfaz2() == 2) { 
				break; 
			}
		}
	}
	if (interfaz1() == "a") {
		codigo = generarCodigo(codigo);
		rewind(stdin);
		interfaz1();
	}

}
}


