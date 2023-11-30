#include "Usuario.h"
#include "hpdf.h"
#include  "hpdf_types.h"
#include<iostream>
#include<filesystem>
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

void error_handler(HPDF_STATUS   error_no, HPDF_STATUS   detail_no, void* user_data){
	/* throw exception when an error has occured */
	printf("ERROR: error_no=%04X, detail_no=%d\n", (unsigned int)error_no,
		(int)detail_no);
	throw std::exception();
}
float Usuario::calcularIMS() {
	float indice = (_peso / (_altura * _altura));
	return indice;
}
void Usuario::generarFactura() {
	
	std::filesystem::path ubicacionProyecto = std::filesystem::current_path();
	std::filesystem::path rutaCompleta = ubicacionProyecto / "Facturas" / (getNombre()+".pdf");
	std::string rutaArchivo = rutaCompleta.string();

	try {

		std::filesystem::create_directory(ubicacionProyecto / "Facturas");
		HPDF_Doc pdf = HPDF_New(error_handler,NULL);
		HPDF_Page page = HPDF_AddPage(pdf);
		HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

		HPDF_Page_BeginText(page);	
		HPDF_Font font = HPDF_GetFont(pdf, "Courier", NULL);
		HPDF_Page_SetFontAndSize(page, font, 12);
		HPDF_Page_TextOut(page, 50, 790, ("Fecha: " + getFechaCreacion()).c_str());
		HPDF_Page_TextOut(page, 50, 760, ("nombre: " + getNombre()+" "+getApellido()).c_str());
		HPDF_Page_TextOut(page, 50, 740, ("Cedula: " + std::to_string(getcedula())).c_str());
		HPDF_Page_TextOut(page, 50, 720, ("Telefono: " + std::to_string(getTelefono())).c_str());
		HPDF_Page_TextOut(page, 50, 700, ("Plan: " + getPlan()).c_str());
		HPDF_Page_TextOut(page, 50, 680, ("--------------------------------"));
		HPDF_Page_TextOut(page, 50, 670, ("--------------------------------"));
		HPDF_Page_TextOut(page, 50, 650, ("valor total: 100.000"));
		HPDF_Page_EndText(page);
		
		if (HPDF_SaveToFile(pdf, rutaArchivo.c_str()) != HPDF_OK) {
			std::cerr << "Error al intentar guardar el archivo PDF: " << HPDF_GetError(pdf) << std::endl;
		}	

		HPDF_Free(pdf);

	}
	catch (const std::exception& e) {
		std::cerr << "Error genérico: " << e.what() << "\n";
	}
	
	std::cout << "factura generada en la ruta: " << rutaArchivo;
}
