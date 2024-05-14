#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define DIM 50
#define DIMr 30

struct habitacion {
	int capacidadHab;//No rellenar al pedir datos del usuario
	int n_personas; //No rellenar al pedir datos del usuario
	int n_dias;
	char tipo_hab;//No rellenar al pedir datos del usurio
	char parking, nombre[15], apellido[15], fecha[12],telefono[10];
	char libre; //libre L ocupado O //No rellenar al pedir datos del usurio
	//int precioHabitacion; // Precio Habitacion
};

struct restaurante {

	int n_personas, opc, dia, hora, min;
	char telefono[15], nombre[15], apellido[15];
	char libre;
};

struct habitacion a[DIM];
struct restaurante b[DIMr];

void RellenarTiposHab(struct habitacion*);
void RellenarMesas(struct restaurante*);

void menu();
//opcion 1

void ReservaHabitacion(struct habitacion*);
void CompletarDatosHab(struct habitacion*, int);
//opcion 2
void ConsultaHabitacion(struct habitacion*);
//opcion 3
void CancelarReservaHab(struct habitacion*);
void ReiniciarHabitacion(struct habitacion*, int);
//opcion 4
void ReservaRestaurante(struct restaurante*);
void CompletarDatosRes(struct restaurante*, int);
//opcion 5
void CancelarReservaRes(struct restaurante*);
void ReiniciarMesa(struct restaurante*, int);
//opcion 6
void Checkout(struct habitacion*);

void main()
{
	
	RellenarTiposHab(a);
	RellenarMesas(b);
	menu();

}



void menu() {
	int opc;
	int opc2;
	


	do {
		printf("***********************************************************\n");
		printf("            INTRODUZCA OPCI%CN DE MENU:\n\n", 162);
		printf("        1 - Reservar una habitaci%cn:\n\n", 162);
		printf("        2 - Consulta de reserva:\n\n");
		printf("        3 - Cancelar reserva de habitaciò:\n\n");
		printf("        4 - Reserva del restaurante:\n\n");
		printf("        5 - Cancelar reserva del restaurante:\n\n");
		printf("        6 - Realizar checkout:\n\n");
		printf("        7 - Salir del programa:\n\n");
		printf("***********************************************************\n");
		printf("Introduzca Opci%cn:", 162);
		scanf_s("%d", &opc);

		switch (opc) {
		case 1: printf("Ha introducido la opcion 1: RESERVAR UNA HABITACION.\n");
			
			ReservaHabitacion(a);
			printf(" ¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				
				menu();
			else
				printf("¡Que pase un buen dia!");


			break;

		case 2: printf("Ha introducido la opcion 2: CONSULTAR RESERVA.\n");

			ConsultaHabitacion(a);

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				
				
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;


		case 3: printf("Ha introducido la opcion 3: CANCELAR RESERVA\n");

            CancelarReservaHab(a);

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;


		case 4: printf("Ha introducido la opcion 4:RESERVAR RESTAURANTE.\n");
			ReservaRestaurante(b);
			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;

		case 5: printf("Ha introducido la opcion 5: CANCELAR RESERVA RESTAURANTE\n");

            CancelarReservaRes(b);

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;

		case 6: printf("Ha introducido la opcion 6: REALIZAR CHECK-OUT\n");


			Checkout(a);


			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;

		case 7: printf("¡Que pase un buen dia!");
			break;
		}

	} while (opc < 0 || opc > 7);

}
/**********************************************************************************/
/*                                                                                */
/*                RELLENAR LOS TIPOS DE HABITACION DEL HOTEL                      */
/**********************************************************************************/


void RellenarTiposHab(struct habitacion* a) {
	int i;
	//10 hab simples 

	for (i = 0; i < 10; i++) {
		a[i].capacidadHab = 1;
		a[i].tipo_hab = 'S';
		a[i].libre = 'L';
		 //Precio habitacion simple 50€
	}
	//20 hab dobles 
	for (i = 10; i < 30; i++) {
		a[i].capacidadHab = 2;
		a[i].tipo_hab = 'D';
		a[i].libre = 'L';
		 //Precio habitacion doble 70€
	}
	//10 hab triples 
	for (i = 30; i < 40; i++) {
		a[i].capacidadHab = 3;
		a[i].tipo_hab = 'T';
		a[i].libre = 'L';
		 //Precio habitacion triple 100€
	}
	//10 hab cuadruples 
	for (i = 40; i < 50; i++) {
		a[i].capacidadHab = 4;
		a[i].tipo_hab = 'C';
		a[i].libre = 'L';
		 //Precio habitacion cuadruple 120€
	}



}
void RellenarMesas(struct restaurante* b) {
	int i;
	for (i = 0; i < DIMr; i++) {
		b[i].libre = 'L';
	}
}
/**********************************************************************************/
/*                                                                                */
/*                RESERVAR UNA HABITACION EN EL HOTEL                             */
/**********************************************************************************/
void ReservaHabitacion(struct habitacion* a) {
	
	int personas;
	int i = 0;
	int encontradoLibre = 0;

	do {
		printf("Introduzca numero de personas:");
		scanf_s("%d", &personas);
		switch (personas) {
		case 1: /*BUSCAMOS HABITACION SIMPLE*/

            int i = 0;
			for (i = 0; i < 10 && encontradoLibre == 0; i++) {
				if (a[i].libre == 'L') { /* Se ha encontrado habitación LIBRE */
					encontradoLibre = 1;
					a[i].libre = 'O';
				}
				
			}

			
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
					a[i].libre = 'O';
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
					a[i].libre = 'O';
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
					a[i].libre = 'O';
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

	CompletarDatosHab(a, i);
	int h = 2;
	while (h != 1 && h != 0)
	{
		printf("\nEscribe 1 si quiere confirmar su reserva, 0 si quiere cancelarla\n");
		scanf_s("%d", &h);
	}
	if (h == 1) {
		printf("Habitacion %d reservada\n", i);
	}
	else {
		ReiniciarHabitacion(a, i);
		printf("\nSe ha cancelado la reserva\n");
	}
		

}
/***********************************************************************/
/*             COMPLETAR DATOS DE LA HABITACION                        */
/***********************************************************************/
void CompletarDatosHab(struct habitacion* a, int i) {
	getchar();
	printf("%cCu%cl ser%c su d%ca de llegada (Recuerde formato DD/MM/YYYY)?\n", 168, 160, 160, 161);
	gets_s(a[i].fecha);
	
	printf("%cCu%cnto  durar%c su estancia en noches?\n", 168, 160, 160);
	scanf_s("%d", &a[i].n_dias);


	printf("%cNecesitar%c parking?\t Responda con S para si o N para no.\n", 168, 160);
	do {
		scanf_s("%c", &a[i].parking);

	} while (a[i].parking != 's' && a[i].parking != 'S' && a[i].parking != 'n' && a[i].parking != 'N');
	printf("DATOS PERSONALES DE LA PERSONA QUE HACE LA RESERVA\n");
	getchar();
	printf("    Escriba su nombre:");
	gets_s(a[i].nombre);
	printf("\n");
	
	printf("    Escriba su apellido:");
	gets_s(a[i].apellido);
	printf("\n");
	printf("Escriba su n%cmero de tel%cfono\n", 163, 130);
	gets_s(a[i].telefono);

}

/*************************************************************************************/
/*        Funcion: Consultar Datos de la Habitación, a partir del número del nombre  */
/*									y el apellido                                    */  
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

	int check = 0;


	for (i = 0; i < DIM; i++) {

		if ((strcmp(a[i].nombre, nombre) == 0) && (strcmp(a[i].apellido, apellido) == 0))

		{

			check = 1;


			printf("DATOS DE LA RESERVA:\n");

			printf("\nNombre de contacto: %s %s\n", nombre, apellido);

			printf("\nNumero de telefono: %s\n", a[i].telefono);

			printf("\nTipo de Habitacion: %c\n", a[i].tipo_hab);

			printf("\nDia de llegada: %s\n", a[i].fecha);

			printf("\nNumero de noches: %d\n", a[i].n_dias);

			printf("\nUso del parking (S o N): %c\n", a[i].parking);

			
		}

	}
	if (check == 0) {
		printf("El nombre %s %s no se encuentra en nuestra base de datos", nombre, apellido);
	}
}


void ReservaRestaurante(struct restaurante* b) {
	int i;
	int mesa_libre=0;
	for (i = 0; i < DIMr && mesa_libre == 0; i++) {
		if (b[i].libre == 'L') { /* Se ha encontrado habitación LIBRE */
			mesa_libre = 1;
			b[i].libre = 'O';
		}

	}
	
	
	if (i == DIMr-1) {
		printf("No hay mesas disponibles:\n");
		printf("Si desea hacer otro cosa vuelva al menu\n");
		
		menu();

	}
CompletarDatosRes(b, i);
int h = 2;
while (h != 1 && h != 0)
{
	printf("\nEscribe 1 si quier confirmar su reserva y 0 si quiere cancelarla\n");
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
/*        Funcion: Restablecer todos los campos de la habitación a sus valores iniciales */                      
/*****************************************************************************************/
void ReiniciarHabitacion(struct habitacion* a, int i) {
	int n;
	for (n = 0; n < 14; n++)
	{
		a[i].nombre[n] = '\0';
		a[i].apellido[n] = '\0';
		a[i].telefono[n] = '\0';
	}
	
	a[i].n_personas = '\0';
	a[i].n_dias = 0;
	a[i].parking = '\0';
	a[i].libre = 'L';

}

/**************************************************************************************************************/
/*        Funcion: Hace que la habitacion vuelva a estar disponible y llama a la funcion ReiniciarHabitacion  */
/**************************************************************************************************************/
void CancelarReservaHab(struct habitacion* a) {

	int i; 
	char nombre[15], apellido[15],telefono[15];
	getchar();
	printf("Introduzca los siguientes datos:\n");
	printf("\nNombre:");
	gets_s(nombre);

	printf("\nApellido:");
	gets_s(apellido);

    printf("\nTelefono:");
	gets_s(telefono);


	int w = 0;
	for (i = 0; i < DIM; i++) 
	{
		
		if ((strcmp(a[i].nombre, nombre) == 0) && (strcmp(a[i].apellido, apellido) == 0) && (strcmp(a[i].telefono, telefono)==0))
		{
		
			ReiniciarHabitacion(a, i);
			a[i].libre = 'L';
			w = 1;
		}
	}
	if (w == 0)
	{
		printf("Ninguna habitacion coincide con los datos dados\n");
	}
	else
		printf("Su cancelacion se ha realizado correctamenete\n");

}

void ReiniciarMesa(struct restaurante* b, int i) {
	int n;
	for (n = 0; n < 14; n++)
	{
		b[i].nombre[n] = '\0';
		b[i].apellido[n] = '\0';
		b[i].telefono[n] = '\0';
	}

	b[i].n_personas = 0;
	b[i].opc = 0;
	b[i].dia = 0;
	b[i].hora = 0;
	b[i].min = 0;
	b[i].libre = 'L';

}

void CancelarReservaRes(struct restaurante* b) {

	int i;
	char nombre[15], apellido[15], telefono[15];
	getchar();
	printf("Introduzca los siguientes datos:\n");
	printf("\nNombre:");
	gets_s(nombre);

	printf("\nApellido:");
	gets_s(apellido);

	printf("\nEscriba su n%cmero de tel%cfono\n", 163, 130);
	gets_s(telefono);
	int w = 0;
	for (i = 0; i < DIM; i++)
	{
		if ((strcmp(b[i].nombre, nombre) == 0) && (strcmp(b[i].apellido, apellido) == 0) && (b[i].telefono == telefono))
		{

		ReiniciarMesa(b, i);
		w = 1;
	    }
	}
	if (w == 0)
	{
		printf("Ninguna mesa coincide con los datos dados\n");
	}
	else
		printf("Su cancelacion se ha realizado correctamenete\n");
}

void Checkout(struct habitacion* a) {

	int i = 0;
	char nombre[15], apellido[15];
	int precio=0;
	getchar();
	printf("Introduzca los siguientes datos:\n");
	printf("\nNombre:");
	gets_s(nombre);
	
	printf("\nApellido:");
	gets_s(apellido);
	
	int check = 0;


	for (i = 0; i < DIM; i++) {

		if ((strcmp(a[i].nombre, nombre) == 0) && (strcmp(a[i].apellido, apellido) == 0))

		{

			check = 1;


			printf("CHECKOUT DE LA RESERVA:\n");

			printf("\nNombre de contacto: %s %s\n", nombre, apellido);

			printf("\nN%cmero de tel%cfono: %s\n", 163, 130,  a[i].telefono);

			printf("\nTipo de Habitaci%cn: %c\n", 162, a[i].tipo_hab);

			if (a[i].tipo_hab == 'S')
				precio = 50;

			if (a[i].tipo_hab == 'D')
				precio = 70;

			if (a[i].tipo_hab == 'T')
				precio = 100;

			if (a[i].tipo_hab == 'C')
				precio = 120;


			printf("\nD%ca de llegada: %s\n", 161, a[i].fecha);

			printf("\nN%cmero de noches: %d\n", 130, a[i].n_dias);

			printf("\nUso del parking (S o N): %c\n", a[i].parking);

			printf("Precio total: %d%c\n", (a[i].n_dias) * precio,36);

			printf("Checkout realizado. Que pase un buen d%ca.\n",161);

		}

	}
	if (check == 0) {
		printf("El nombre %s %s no se encuentra en nuestra base de datos", nombre, apellido);
	}
}
