#pragma once
#include<iostream>
#include<string>
#include<list>

#include"Usuario.h"

class Gimnasio
{
private:
	int _capacidad=0;
	std::list<std::string> _inventario;
	std::list<Usuario> _listaUsuarios;
public:
	int mostrarUsuarios();
	void agregarUsuario(Usuario nuevoUsuario);
	void eliminarUsuario();
};


