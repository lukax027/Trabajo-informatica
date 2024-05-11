#include <stdio.h>
#include <malloc.h>
#define DIM 50
#define DIMn 9
#define DIMr 30

struct habitacion {
	int capacidadHab;//No rellenar al pedir datos del usuario
	int n_personas; //No rellenar al pedir datos del usuario
	int n_dias;
	char tipo_hab;//No rellenar al pedir datos del usurio
	char parking, nombre[15], apellido[15], telefono[15], fecha[12];
	char libre; //libre L ocupado O //No rellenar al pedir datos del usurio
};

struct restaurante {

	int n_personas, opc, dia, hora, min;
	char telefono[15], nombre[15], apellido[15];
	char libre;
};

void RellenarTiposHab(struct habitacion*);
void RellenarMesas(struct restaurante*);
void menu(struct habitacion*,struct restaurante*);
//opcion 1
void ReservaHabitacion(struct habitacion*,struct restaurante*);
void CompletarDatosHab(struct habitacion*, int);
//opcion 2
void ConsultaHabitacion(struct habitacion*, char*);
//opcion 4
void ReservaRestaurante(struct habitacion*, struct restaurante*);
void CompletarDatosRes(struct restaurante*, int);


void main()
{
	struct habitacion a[DIM];
	struct restaurante b[DIMr];
	RellenarTiposHab(a);
	RellenarMesas(b);
	menu(a,b);	//llamada a la funcion menú.
}

void menu(struct habitacion* a,struct restaurante *b) {
	

	int opc;
	int opc2;
	char numero_buscar[DIMn];


	do {
		printf("Introduzca opci%cn:\n", 162);
		printf("1 Reservar una habitaci%cn:\n", 162);
		printf("2 Consulta de reserva:\n");
		printf("3 Cancelar reserva:\n");
		printf("4 Reserva del restaurante:\n");
		printf("5 Cancelar reserva del restaurante:\n");
		printf("6 Realizar checkout:\n");
		printf("7 Salir del programa:\n");
		scanf_s("%d", &opc);

		switch (opc) {
		case 1: printf("Ha introducido la opcion 1.\n");
			ReservaHabitacion(a,b);

			printf(" ¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a,b);
			else
				printf("¡Que pase un buen dia!");


			break;

		case 2: printf("Ha introducido la opcion 2.\n");
			printf("Introduzca su numero de telefono:\n");
			gets_s(numero_buscar);
			ConsultaHabitacion(a, numero_buscar);

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a,b);
			else
				printf("¡Que pase un buen dia!");

			break;


		case 3: printf("Ha introducido la opcion 3.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a,b);
			else
				printf("¡Que pase un buen dia!");

			break;


		case 4: printf("Ha introducido la opcion 4.\n");
			ReservaRestaurante(a,b);
			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a,b);
			else
				printf("¡Que pase un buen dia!");

			break;

		case 5: printf("Ha introducido la opcion 5.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a,b);
			else
				printf("¡Que pase un buen dia!");

			break;

		case 6: printf("Ha introducido la opcion 6.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a,b);
			else
				printf("¡Que pase un buen dia!");

			break;

		}

	} while (opc < 0 || opc > 7);

}



void RellenarTiposHab(struct habitacion* a) {
	int i;
	//10 hab simples  50€

	for (i = 0; i < 10; i++) {
		a[i].capacidadHab = 1;
		a[i].tipo_hab = 'S';
		a[i].libre = 'L';
	}
	//20 hab dobles 70€
	for (i = 10; i < 30; i++) {
		a[i].capacidadHab = 2;
		a[i].tipo_hab = 'D';
		a[i].libre = 'L';
	}
	//10 hab triples 100€
	for (i = 30; i < 40; i++) {
		a[i].capacidadHab = 3;
		a[i].tipo_hab = 'T';
		a[i].libre = 'L';
	}
	//10 hab cuadruples 120€
	for (i = 40; i < 50; i++) {
		a[i].capacidadHab = 4;
		a[i].tipo_hab = 'C';
		a[i].libre = 'L';
	}



}
void RellenarMesas(struct restaurante* b) {
	int i;
	for (i = 0; i < 30; i++) {
		b[i].libre = 'L';
	}
}
void ReservaHabitacion(struct habitacion* a,struct restaurante *b) {
	int personas;

	int i;
	do {
		printf("Introduzca numero de personas:");
		scanf_s("%d", &personas);
		switch (personas) {
		case 1:

			
			for (i = 0; i < 10; i++) {
				if (a[i].libre == 'L')
					break;
			}

			if (i == 9) {
				printf("No hay habitaciones simples disponibles:");
				printf("Si desea reservar una doble vuelva al menu.");
				menu(a,b);

			}
			else
			{
				CompletarDatosHab(a, i);
				printf("Habitacion %d reservada\n",i);
			}

			break;

		case 2:

			for (i = 10; i < 30; i++) {
				if (a[i].libre == 'L')
					break;
			}

			if (i == 29) {
				printf("No hay habitaciones dobles disponibles:");
				printf("Si desea reservar una triple vuelva al menu.");
				menu(a,b);

			}
			else CompletarDatosHab(a, i);


			break;

		case 3:

			for (i = 30; i < 40; i++) {
				if (a[i].libre == 'L')
					break;
			}
			if (i == 39) {
				printf("No hay habitaciones triples disponibles:");
				printf("Si desea reservar una cuadruple vuelva al menu.");
				menu(a,b);

			}
			else CompletarDatosHab(a, i);


			break;

		case 4:

			for (i = 40; i < 50; i++) {
				if (a[i].libre == 'L')
					break;
			}


			if (i == 49) {
				printf("No hay habitaciones cuadruples disponibles:");
				printf("Si desea reservar otra habitacion vuelva al menu.");
				menu(a,b);

			}
			else CompletarDatosHab(a, i);



			break;

		default: printf("Numero no valido de personas.\n");
		}
	} while (personas < 0 || personas>4);
	printf("Adios");
}

void CompletarDatosHab(struct habitacion* a, int i) {
	getchar();
	printf("%cCu%cl ser%c su d%ca de llegada?\n", 168, 160, 160, 161);
	gets_s(a[i].fecha);
	getchar();
	printf("%cCu%cnto  durar%c su estancia en noches?\n", 168, 160, 160);
	scanf_s("%d", &a[i].n_dias);


	printf("%cNecesitar%c parking?\t Responda con S para si o N para no.\n", 168, 160);
	do {
		scanf_s("%c", &a[i].parking);

	} while (a[i].parking != 's' && a[i].parking != 'S' && a[i].parking != 'n' && a[i].parking != 'N');

	printf("Escriba su nombre\n");
	gets_s(a[i].nombre);
	getchar();
	printf("Escriba su apellido\n");
	gets_s(a[i].apellido);
	getchar();
	printf("Escriba su n%cmero de tel%cfono\n", 163, 130);
	gets_s(a[i].telefono);
	getchar();
	a[i].libre = 'O';

}

void ConsultaHabitacion(struct habitacion* a, char* numero_buscar) {
	int i, j;
	for (i = 0; i < DIM; i++) {
		
			if (a[i].telefono == numero_buscar) {
				printf("Usted tiene reservada la habitacion numero %d\n", i);
				printf("Esta es su reserva:\n");
				printf("Dia de llegada:%s\n", a[i].fecha);
				printf("Numero de dias:%d\n", a[i].n_dias);
				printf("Parking:%c", a[i].parking);
				printf("Nombre:%s", a[i].nombre);
				printf("Apellido:%s", a[i].apellido);

			}
		
	}
}

void ReservaRestaurante(struct habitacion *a,struct restaurante* b) {

	int i;
	for (i = 0; i < 30; i++) {
		if (b[i].libre == 'L')
			break;
	}

	if (i == 29) {
		printf("No hay mesas disponibles:");
		printf("Si desea hacer otro cosa vuelva al menu");
		menu(a, b);

	}
	else
	{
		CompletarDatosRes(b, i);
		printf("Mesa %d reservada\n", i);
	}
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


	printf("Escriba su nombre\n");
	gets_s(b[i].nombre);
	getchar();

	printf("Escriba su apellido\n");
	gets_s(b[i].apellido);
	getchar();

	printf("Escriba su n%cmero de tel%cfono\n", 163, 130);
	gets_s(b[i].telefono);
	getchar();
}
