//****************************************************************************************************
// PROGRAMA PARA LA GESTÍON DE HOTEL Y RESTAURANTE
// DESARROLLADO POR:
//     - RAUL GUADAÑO
//     
//     
//     -
// ****************************************************************************************************




#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define DIM 50
#define DIMr 30

//***********************************
// DEFINIMOS ESTRUCTURA HABITACION
//**********************************
struct habitacion {

	int capacidadHab;  //No rellenar al pedir datos del usuario
	int n_personas;    //No rellenar al pedir datos del usuario
	int n_dias;
	char tipo_hab;    //No rellenar al pedir datos del usurio
	char parking, nombre[15], apellido[15], fecha[12], telefono[10];
	char libre; //libre L ocupado O //No rellenar al pedir datos del usurio
	//int precioHabitacion; // Precio Habitacion
};
//************************************
// DEFINIMOS ESTRUCTURA RESTAURANTE
//**********************************
struct restaurante {

	int n_personas, opc, dia, hora, min;
	char telefono[15], nombre[15], apellido[15];
	char libre; //libre = L, Ocupado = O //No rellenar al pedir datos del usurio
};

struct habitacion a[DIM];   // Array que almacena las habitaciones del hotel
struct restaurante b[DIMr]; // Array que almacena las mesaas del restaurante del hotel

// Necesario al inicio - Carg inicial de datos

//void LeerHabitacionesArchivo(struct habitacion*, FILE*); //Cargar desde archivo
//void LeerMesasRestaurante(struct restaurante*, FILE*);   //Cargar desde archivo

void RellenarTiposHab(struct habitacion*);
void RellenarMesas(struct restaurante*);

void menu();

// OPCION 1- RESERVAR HABITACION

void ReservaHabitacion(struct habitacion*);
void CompletarDatosHab(struct habitacion*, int);

//OPCION 2 - CONSULTAR RESERVA HABITACION

void ConsultaHabitacion(struct habitacion*);

//OPCION 3 - CANCELAR RESERVA HABITACION

void CancelarReservaHab(struct habitacion*);
void ReiniciarHabitacion(struct habitacion*, int);

//OPCION 4 - RESERVAR MESA RESTAURANTE

void ReservaRestaurante(struct restaurante*);
void CompletarDatosRes(struct restaurante*, int);

// OPCION 5 - CANCELAR MESA RESTAURANTE

void CancelarReservaRes(struct restaurante*);
void ReiniciarMesa(struct restaurante*, int);

// OPCION 6- CHECK OUT
void Checkout(struct habitacion*);

// OPCION 7- SALIR
//void RellenarHabitacionesArchivo(struct habitacion*, FILE*);      // Escribir en el archivo
//void RellenarMesasRestauranteArchivo(struct restaurante*, FILE*); // Escribir en el archivo

// PROGRAMA PRINCIPAL
void main()
{
	/*FILE* habitaciones, * restaurante;
	errno_t error;

	error = fopen_s(&habitaciones, "ReservasHabitacion.txt", "a+");

	if (error == 0)
		printf("Archivo abierto correctamente\n");
	else
		printf("No se ha podido abrir el archivo.\n");

	error = fopen_s(&restaurante, "ReservasMesasRestaurante.txt", "a+");

	if (error == 0)
		printf("Archivo abierto correctamente\n");
	else
		printf("No se ha podido abrir el archivo.\n");

	if (habitaciones == NULL)
		RellenarTiposHab(a);
	else
		//LeerHabitacionesArchivo(a, habitaciones);

	if (restaurante == NULL)
		RellenarMesas(b);
	else
		//LeerMesasRestaurante(b, restaurante);

*/
	RellenarTiposHab(a);
	RellenarMesas(b);
	menu();

}
/***********************************************************************************/
/*                                                                                 */
/*                MENU PRINCIPAL:                                                  */
/*                 1 - Reservar una habitacion                                     */
/*                 2 - Consulta de reserva                                         */
/*	               3 - Cancelar reserva de habitacion                              */
/*		           4 - Reserva del restaurante                                     */
/*		           5 - Cancelar reserva del restaurante                            */
/*		           6 - Realizar checkout                                           */
/*		           7 - Salir del programa                                          */
/***********************************************************************************/
/* MENU PRINCIPAL */
void menu() {
	int opc;  // Variable - opción de menu
	int opc2; // Variable - opción para salir del programa  = 0 o volver al menu = 1

	do {
		printf("***********************************************************\n");
		printf("            BIENVENIDO AL ****GRAN HOTEL****:\n\n\n\n\n", 162);
		printf("            INTRODUZCA OPCI%CN DE MENU:\n\n", 162);
		printf("        1 - RESERVAR UNA HABITACI%CN:\n\n", 162);
		printf("        2 - CONSULTAR RESERVA DE HABITACI%CN:\n\n", 162);
		printf("        3 - CANCELAR RESERVA DE HABITACI%CN:\n\n", 162);
		printf("        4 - RESERVA MESA EN COMEDOR RESTAURANTE:\n\n");
		printf("        5 - CANCELAR MESA COMEDOR RESTAURANTE:\n\n");
		printf("        6 - REALIZAR CHECKOUT:\n\n");
		printf("        7 - SALIR DEL PROGRAMA:\n\n\n\n\n");
		printf("***********************************************************\n");
		printf("INTRODUZCA OPCI%cN:", 162);
		scanf_s("%d", &opc);

		switch (opc) {
		case 1: printf("Ha introducido la opcion 1: RESERVAR UNA HABITACION.\n");

			ReservaHabitacion(a);
			break;

		case 2: printf("Ha introducido la opcion 2: CONSULTAR RESERVA.\n");

			ConsultaHabitacion(a);
			break;


		case 3: printf("Ha introducido la opcion 3: CANCELAR RESERVA\n");

			CancelarReservaHab(a);
			break;


		case 4: printf("Ha introducido la opcion 4:RESERVAR RESTAURANTE.\n");
			ReservaRestaurante(b);
			break;

		case 5: printf("Ha introducido la opcion 5: CANCELAR RESERVA RESTAURANTE\n");

			CancelarReservaRes(b);


			break;

		case 6: printf("Ha introducido la opcion 6: REALIZAR CHECK-OUT\n");
			Checkout(a);

			break;

		case 7: printf("¡ QUE PASE UN BUEN DIA !");
			// guardar sesión habitaciones en archivo EscribirHabitacionFichero
			// cerrar archivo
			break;
		}
		printf(" %cDESEA HACER ALGUNA OTRA COSA ?\n",168);
		printf("Introduzca 1 para <1=VOLVER AL MENU> o 0 para <0=SALIR DEL PROGRAMA>:");
		scanf_s("%d", &opc2);
		if (opc2 == 1)
			menu();
		else
			printf("¡ QUE PASE UN BUEN DIA !");
	} while (opc < 0 || opc > 7);


}
/**********************************************************************************/
/*                                                                                */
/*                RELLENAR TIPOS HABITACION DEL HOTEL:                            */
/*                Completa las habitaciones del hotel, diviendolo en 4 tipos      */
/*                -10 habitaciones Simples                                         */
/*                -20 habitaciones Dobless                                         */
/*                -10 habitaciones Triples                                         */
/*                -10 habitaciones Cuadruples                                      */
/**********************************************************************************/


void RellenarTiposHab(struct habitacion* a) {
	int simple, doble, triple, cuadruple;
	//10 hab simples 

	for (simple = 0; simple < 10; simple++) {

		a[simple].capacidadHab = 1;
		a[simple].tipo_hab = 'S';
		a[simple].libre = 'L';
		//Precio habitacion simple 50€
	}
	//20 hab dobles 
	for (doble = 10; doble < 30; doble++) {

		a[doble].capacidadHab = 2;
		a[doble].tipo_hab = 'D';
		a[doble].libre = 'L';
		//Precio habitacion doble 70€
	}
	//10 hab triples 
	for (triple = 30; triple < 40; triple++) {

		a[triple].capacidadHab = 3;
		a[triple].tipo_hab = 'T';
		a[triple].libre = 'L';
		//Precio habitacion triple 100€
	}
	//10 hab cuadruples 
	for (cuadruple = 40; cuadruple < 50; cuadruple++) {

		a[cuadruple].capacidadHab = 4;
		a[cuadruple].tipo_hab = 'C';
		a[cuadruple].libre = 'L';
		//Precio habitacion cuadruple 120€
	}

}

/**********************************************************************************/
/*                                                                                */
/*                RELLENAR MESAS DEL RESTAURANTE:                                 */
/*                Inicializa las mesas del restaurante a Libre                    */
/*                                                                                */
/**********************************************************************************/

void RellenarMesas(struct restaurante* b) {
	int i;
	for (i = 0; i < DIMr; i++) {
		b[i].libre = 'L';
	}
}
/**********************************************************************************/
/*                                                                                */
/*                RESERVAR HABITACION:                                            */
/*                Localiza habitación libre según nro de personas                 */
/**********************************************************************************/
void ReservaHabitacion(struct habitacion* a) {

	int personas;             // Nro de personas que ocuparán la habitación
	int i;                    // Indice para recorrer las habitaciones
	int nroHabitacion = 0;    // Nro de habitación Libre encontrada
	int encontradoLibre = 0;  // Sale del bucle cuando encuentra una habitación Libre

	do {
		printf("Introduzca numero de personas:");
		scanf_s("%d", &personas);
		switch (personas) {
		case 1: /*BUSCAMOS HABITACION SIMPLE*/

			for (i = 0; i < 10 && encontradoLibre == 0; i++) {
				if (a[i].libre == 'L') { /* Se ha encontrado habitación LIBRE */
					encontradoLibre = 1;
					nroHabitacion = i;

				}
			}
			printf("habitacion encontrada:%d", nroHabitacion);
			if (encontradoLibre == 0) { //No se han encontrado habitaciones simples Libres
				printf("No hay habitaciones simples disponibles:");
				printf("Si desea reservar una doble vuelva al menu.");
				menu();

			}
			break;

		case 2: /* BUSCAMOS HABITACION DOBLE */

			for (i = 10; i < 30 && encontradoLibre == 0; i++) {
				if (a[i].libre == 'L') { /* Se ha encontrado habitación LIBRE DOBLE */
					encontradoLibre = 1;
					nroHabitacion = i;
				}
			}

			if (encontradoLibre == 0) { //No se han encontrado habitaciones DOBLES Libres */
				printf("No hay habitaciones dobles disponibles:");
				printf("Si desea reservar una triple vuelva al menu.");
				menu();

			}
			break;

		case 3: /* BUSCAMOS HABITACION TRIPLE*/

			for (i = 30; i < 40 && encontradoLibre == 0; i++) {
				if (a[i].libre == 'L') { /* Se ha encontrado habitación LIBRE TRIPLE */
					encontradoLibre = 1;
					nroHabitacion = i;
				}

			}
			if (i == 39) {
				printf("No hay habitaciones triples disponibles:");
				printf("Si desea reservar una cuadruple vuelva al menu.");

				menu();
			}



			break;

		case 4: /* BUSCAMOS HABITACION CUADRUPLE */

			for (i = 40; i < 50 && encontradoLibre == 0; i++) {
				if (a[i].libre == 'L') { /* Se ha encontrado habitación LIBRE TRIPLE */
					encontradoLibre = 1;
					nroHabitacion = i;
				}

			}
			if (i == 49) {
				printf("No hay habitaciones cuadruples disponibles:");
				printf("Si desea reservar otra habitacion vuelva al menu.");

				menu();

			}

			break;

		default: printf("Numero no valido de personas.\n");
		}
	} while (personas < 0 || personas>4);

	CompletarDatosHab(a, nroHabitacion);
	int confirmar = 2;
	while (confirmar != 1 && confirmar != 0)
	{
		printf("\nEscribe 1 si quiere <1-CONFIRMAR RESERVA>, 0 si quiere <0-CANCELAR RESERVA>\n");
		scanf_s("%d", &confirmar);
	}
	if (confirmar == 1) {
		printf("Habitacion %d reservada\n", nroHabitacion);
	}
	else {
		ReiniciarHabitacion(a, nroHabitacion);
		printf("\nSe ha cancelado la reserva\n");
	}


}
/****************************************************************************************/
/*             COMPLETARDATOSHABITACION:                                                */
/*             Rellena los datos de la habitacion, le pasa por parametro nro habitacion */
/****************************************************************************************/
void CompletarDatosHab(struct habitacion* a, int nro) {

	getchar();
	printf("%cCu%cl ser%c su d%ca de llegada (Recuerde formato DD/MM/YYYY)?\n", 168, 160, 160, 161);
	gets_s(a[nro].fecha);

	printf("%cCu%cnto  durar%c su estancia en noches?\n", 168, 160, 160);
	scanf_s("%d", &a[nro].n_dias);


	printf("%cNecesitar%c parking?\t Responda con S para si o N para no.\n", 168, 160);
	do {
		scanf_s("%c", &a[nro].parking);

	} while (a[nro].parking != 's' && a[nro].parking != 'S' && a[nro].parking != 'n' && a[nro].parking != 'N');
	printf("DATOS PERSONALES DE LA PERSONA QUE HACE LA RESERVA\n");
	getchar();
	printf("   **** Escriba su <NOMBRE>:");
	gets_s(a[nro].nombre);
	printf("\n");

	printf("   **** Escriba su <APELLIDO>:");
	gets_s(a[nro].apellido);
	printf("\n");
	printf("   **** Escriba su n%cmero de <TELEL%cFONO>:", 163, 130);
	gets_s(a[nro].telefono);
	a[nro].libre = 'O';

}

/*************************************************************************************/
/*        CONSULTAR HABITACION:                                                      */
/*        Consultar Datos de la Habitación, a partir del NOMBRE Y APELLIDO           */
/*								                                                     */
/*************************************************************************************/
void ConsultaHabitacion(struct habitacion* a) { //CAMBIAR
	int i;
	char nombre[15], apellido[15];
	getchar();
	printf("Introduzca los siguientes datos:\n");
	printf("\nNombre:");
	gets_s(nombre);

	printf("\nApellido:");
	gets_s(apellido);

	int nroHabitacion = 0; // Habitación que ha encontrado
	int check = 0;         // Habitación encontrada para salir del buble

	for (i = 0; i < DIM && check == 0; i++) {

		if ((strcmp(a[i].nombre, nombre) == 0) && (strcmp(a[i].apellido, apellido) == 0))
		{
			nroHabitacion = i;
			check = 1;
		}
	}
	if (check == 1) { // Se encontró la habitación
		printf("DATOS DE LA RESERVA:\n");

		printf("\nNombre de contacto: %s %s\n", nombre, apellido);

		printf("\nNumero de telefono: %s\n", a[nroHabitacion].telefono);

		printf("\nTipo de Habitacion: %c\n", a[nroHabitacion].tipo_hab);

		printf("\nDia de llegada: %s\n", a[nroHabitacion].fecha);

		printf("\nNumero de noches: %d\n", a[nroHabitacion].n_dias);

		printf("\nUso del parking (S o N): %c\n", a[nroHabitacion].parking);


	}
	else 	printf("El nombre %s %s no se encuentra en nuestra base de datos", nombre, apellido);

}
/*************************************************************************************/
/*        RESERVAR RESTAURANTE:                                                      */
/*        Reservar mesa restaurante                                                  */
/*								                                                     */
/*************************************************************************************/

void ReservaRestaurante(struct restaurante* b) {
	int i;
	int mesa_libre = 0;
	for (i = 0; i < DIMr && mesa_libre == 0; i++) {
		if (b[i].libre == 'L') { /* Se ha encontrado habitación LIBRE */
			mesa_libre = 1;
			b[i].libre = 'O';
		}

	}

	if (i == DIMr - 1) {
		printf("No hay mesas disponibles:\n");
		printf("Si desea hacer otro cosa vuelva al menu\n");

		menu();

	}
	CompletarDatosRes(b, i);
	int h = 2;
	while (h != 1 && h != 0)
	{
		printf("\nEscribe 1 si quiere confirmar su reserva y 0 si quiere cancelarla\n");
		scanf_s("%d", &h);
	}
	if (h == 1) {
		printf("Mesa %d reservada\n", i);

	}
	else {
		ReiniciarMesa(b, i);
		printf("\nSe ha cancelado la reserva\n");

	}
	menu();

}


/*************************************************************************************/
/*        COMPLETAR DATOS MESA RESTAURANTE:                                          */
/*        Reservar mesa restaurante                                                  */
/*								                                                     */
/*************************************************************************************/

void CompletarDatosRes(struct restaurante* b, int i) {


	printf("%cCu%cntas personas ser%cn?\n", 168, 160, 160);
	scanf_s("%d", &b[i].n_personas);

	printf("%cQu%c d%ca quiere reservar?\n", 168, 130, 161);
	scanf_s("%d", &b[i].dia);

	printf("Por favor, ingresa una hora en formato xx:xx: ");
	scanf_s("%d:%d", &b[i].hora, &b[i].min);

	if ((b[i].hora >= 0 && b[i].hora <= 23) && (b[i].min >= 0 && b[i].min <= 59))
	{
		printf("La hora ingresada es válida: %d:%d\n", b[i].hora, b[i].min);
	}
	else {
		printf("La hora ingresada no es válida.\n");
	}

	getchar();
	printf("Escriba su nombre\n");
	gets_s(b[i].nombre);


	printf("Escriba su apellido\n");
	gets_s(b[i].apellido);


	printf("Escriba su n%cmero de tel%cfono\n", 163, 130);
	gets_s(b[i].telefono);

}

/*****************************************************************************************/
/*        REINICIARHABITACION:                                                           */
/*        Reestablecer todos los campos de la habitación a sus valores iniciales         */
/*****************************************************************************************/
void ReiniciarHabitacion(struct habitacion* a, int nro) {
	int n;
	for (n = 0; n < 15; n++)
	{
		a[nro].nombre[n] = '\0';
		a[nro].apellido[n] = '\0';
		a[nro].telefono[n] = '\0';
	}

	a[nro].n_personas = '\0';
	a[nro].n_dias = 0;
	a[nro].parking = '\0';
	a[nro].libre = 'L';

}

/*************************************************************************************************************/
/*        CANCELARESERVAHABITACION:                                                                          */
/*        Hace que la habitacion vuelva a estar disponible y llama a la funcion ReiniciarHabitacion          */
/*************************************************************************************************************/
void CancelarReservaHab(struct habitacion* a) {

	int i;
	char nombre[15], apellido[15], telefono[15];
	getchar();
	printf("Introduzca los siguientes datos:\n");
	printf("\nNombre:");
	gets_s(nombre);

	printf("\nApellido:");
	gets_s(apellido);

	printf("\nTelefono:");
	gets_s(telefono);


	int w = 0;              // Variable para salir del bucle cuando encuentra la habitacion
	int nroHabitacion = 0;  // Nro habitacion encontrada
	for (i = 0; i < DIM && w == 0; i++)
	{

		if ((strcmp(a[i].nombre, nombre) == 0) && (strcmp(a[i].apellido, apellido) == 0) && (strcmp(a[i].telefono, telefono) == 0))
		{
			nroHabitacion = i;
			w = 1;
		}
	}

	if (w == 0) // No se encontró la habitacion
	{
		printf("Ninguna habitacion coincide con los datos dados\n");
	}
	else { // Se encontró la habitacion
		ReiniciarHabitacion(a, nroHabitacion);
		printf("La cancelacion de la habitacion %d se ha realizado correctamente\n", nroHabitacion);
	}
}
/**************************************************************************************/
/*        REINICIAR MESA RESTAURANTE: Vacia la mesa y la deja LIBRE                               */
/**************************************************************************************/
void ReiniciarMesa(struct restaurante* b, int nro) {
	int n;
	for (n = 0; n < 15; n++)
	{
		b[nro].nombre[n] = '\0';
		b[nro].apellido[n] = '\0';
		b[nro].telefono[n] = '\0';
	}

	b[nro].n_personas = 0;
	b[nro].opc = 0;
	b[nro].dia = 0;
	b[nro].hora = 0;
	b[nro].min = 0;
	b[nro].libre = 'L';

}
/**************************************************************************************/
/*        CANCELA LA RESERVA DE LA MESA                                               */
/**************************************************************************************/
void CancelarReservaRes(struct restaurante* b) {

	int i;
	char nombre[15], apellido[15], telefono[15];
	getchar();
	printf("Introduzca los siguientes datos:\n");
	printf("\nNombre:");
	gets_s(nombre);

	printf("\nApellido:");
	gets_s(apellido);

	printf("\nTelefono:");
	gets_s(telefono);


	int w = 0;              // Variable para salir del bucle cuando encuentra la habitacion
	int nroMesa = 0;  // Nro habitacion encontrada
	for (i = 0; i < DIM && w == 0; i++)
	{

		if ((strcmp(b[i].nombre, nombre) == 0) && (strcmp(b[i].apellido, apellido) == 0) && (strcmp(b[i].telefono, telefono) == 0))
		{
			nroMesa = i;
			w = 1;
		}
	}

	if (w == 0) // No se encontró la habitacion
	{
		printf("Ninguna habitacion coincide con los datos dados\n");
	}
	else { // Se encontró la habitacion
		ReiniciarHabitacion(a, nroMesa);
		printf("La cancelacion de la habitacion %d se ha realizado correctamente\n", nroMesa);
	}
}
/*******************************************************************************/
/*                        CHECK-OUT- VACIA HABITACION Y FACTURA AL CLIENTE     */
/*******************************************************************************/

void Checkout(struct habitacion* a) {

	int i = 0;

	char nombre[15], apellido[15];
	int precio = 0;
	getchar();
	printf("Introduzca los siguientes datos:\n");
	printf("\nNombre:");
	gets_s(nombre);

	printf("\nApellido:");
	gets_s(apellido);

	int nroHabitacion = 0; // Habitación que ha encontrado
	int check = 0;         // Habitación encontrada para salir del buble
	for (i = 0; i < DIM && check == 0; i++) {
		if ((strcmp(a[i].nombre, nombre) == 0) && (strcmp(a[i].apellido, apellido) == 0))
		{
			check = 1;
			nroHabitacion = i;
		}
	}
	if (check == 1) { // SE ENCONTRÓ LA HABITACION
		printf("CHECKOUT DE LA RESERVA:\n");

		printf("\nSu Nro Habitacion es: %d\n", nroHabitacion);

		printf("\nNombre de contacto: %s %s\n", nombre, apellido);

		printf("\nN%cmero de tel%cfono: %s\n", 163, 130, a[nroHabitacion].telefono);

		printf("\nTipo de Habitaci%cn: %c\n", 162, a[nroHabitacion].tipo_hab);

		if (a[nroHabitacion].tipo_hab == 'S')  precio = 50;

		if (a[nroHabitacion].tipo_hab == 'D') precio = 70;

		if (a[nroHabitacion].tipo_hab == 'T') precio = 100;

		if (a[nroHabitacion].tipo_hab == 'C') precio = 120;

		printf("\nD%ca de llegada: %s\n", 161, a[nroHabitacion].fecha);

		printf("\nN%cmero de noches: %d\n", 130, a[nroHabitacion].n_dias);

		printf("\nUso del parking (S o N): %c\n", a[nroHabitacion].parking);

		printf("Precio total: %d%c\n", (a[nroHabitacion].n_dias) * precio, 36);

		printf("Checkout de la habitacion %d realizado. Que pase un buen d%ca.\n", nroHabitacion,161);
		ReiniciarHabitacion(a, nroHabitacion);

	}
	else printf("El nombre %s %s no se encuentra en nuestra base de datos", nombre, apellido);

}
