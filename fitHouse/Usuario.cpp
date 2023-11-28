#include "Usuario.h"
#include<iostream>
#include<filesystem>
#include<hpdf.h>
//constructor por defecto -> inicializa objetos sin pasarle atributos inmediatamente
Usuario::Usuario() : Persona("", "", "", 0, 0, 0) {
	_peso = 0.0f;
	_altura = 0.0f;
	_fechaCreacion = std::chrono::system_clock::now();
	
}
//constructor que hereda atributos de Persona
Usuario::Usuario(std::string nombre, std::string apellido, std::string sexo, int edad, int cedula, int telefono,
	float peso, float altura,std::string plan, std::string condicionMedica, std::string rutina, std::string historial) :

	Persona(nombre, apellido, sexo, edad, cedula, telefono),
	_peso(peso),
	_altura(altura),
	_plan(plan),
	_condicionMedica(condicionMedica),
	_rutina(rutina),
	_historial(historial),
	_fechaCreacion(std::chrono::system_clock::now())

{}
float Usuario::calcularIMS() {
	float indice = (_peso / (_altura * _altura));
	return indice;
}

void Usuario::generarFactura() {
	// Obtén la ubicación del proyecto
	std::filesystem::path ubicacionProyecto = std::filesystem::current_path();
	// Concatena la carpeta "Facturas" a la ubicación del proyecto
	std::filesystem::path rutaCompleta = ubicacionProyecto / "Facturas" / (getNombre()+".pdf");
	// Convierte la ruta a un string
	std::string rutaArchivo = rutaCompleta.string();

	try
	{
	HPDF_Doc pdf = HPDF_New(nullptr, nullptr);
	//abrir pdf
	HPDF_Page page = HPDF_AddPage(pdf);
	//tamaño
	HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

	HPDF_Page_BeginText(page);
	HPDF_Font font = HPDF_GetFont(pdf, "Arial", nullptr);
	HPDF_Page_SetFontAndSize(page, font, 12);
	HPDF_Page_TextOut(page, 50, 700, ("Factura de pago para: " + getNombre()).c_str());
	HPDF_Page_TextOut(page, 50, 680, ("Fecha de creación: " + getFechaCreacion()).c_str());
	HPDF_Page_TextOut(page, 50, 660, ("Plan seleccionado: " + getPlan()).c_str());

	// Finaliza el flujo de texto
	HPDF_Page_EndText(page);
	// Libera los recursos
	HPDF_Free(pdf);
	// Guarda el PDF en el archivo especificado
	HPDF_SaveToFile(pdf, rutaArchivo.c_str());

	if (HPDF_SaveToFile(pdf, rutaArchivo.c_str()) != HPDF_OK) {
		std::cerr << "Error al intentar guardar el archivo PDF: " << HPDF_GetError(pdf)<< std::endl;
		
	}

	}
	catch (const std::exception&)
	{
		std::cout << "error en la factura";
	}
	
	std::cout << "factura generada en la ruta: " << rutaArchivo;
}
