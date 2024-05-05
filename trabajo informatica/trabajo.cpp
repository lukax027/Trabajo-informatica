#include <stdio.h>
#include <malloc.h>
#define DIM 50

struct habitacion {
	int capacidadHab;//No rellenar al pedir datos del usuario
	int n_personas; //No rellenar al pedir datos del usuario
	char fecha[12];
	int n_dias;
	char tipo_hab;//No rellenar al pedir datos del usurio
	char parking;
	char nombre[15];
	char apellido[15];
	char telefono[15];
	char libre; //libre L ocupado O //No rellenar al pedir datos del usurio
};
struct restaurante {

	int n_personas, opc, dia;
	char telefono[15];
};

void RellenarTiposHab(struct habitacion*);
void menu(struct habitacion*);
void ReservaHabitacion(struct habitacion*);
void CompletarDatosHab(struct habitacion*, int);


void main()
{
	struct habitacion a[DIM];
	RellenarTiposHab(a); //
	menu(a);	//llamada a la funcion menú.
}

void menu(struct habitacion* a) {


	int opc;
	int opc2;


	
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
			ReservaHabitacion(a);

			printf(" ¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 ==	1)
				menu(a);
			else 
				printf("¡Que pase un buen dia!");


			break;

		case 2: printf("Ha introducido la opcion 2.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a);
			else
				printf("¡Que pase un buen dia!");

			break;


		case 3: printf("Ha introducido la opcion 3.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a);
			else
				printf("¡Que pase un buen dia!");

			break;


		case 4: printf("Ha introducido la opcion 4.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a);
			else
				printf("¡Que pase un buen dia!");

			break;

		case 5: printf("Ha introducido la opcion 5.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a);
			else
				printf("¡Que pase un buen dia!");

			break;

		case 6: printf("Ha introducido la opcion 6.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu(a);
			else
				printf("¡Que pase un buen dia!");

			break;

		}

	} while (opc < 0 || opc > 7);

	}



void RellenarTiposHab(struct habitacion* a) {
	int i;
	//10 hab simples 

	for (i = 0; i < 10; i++) {
		a[i].capacidadHab = 1;
		a[i].tipo_hab = 'S';
		a[i].libre = 'L';
	}
	//20 hab dobles
	for (i = 10; i < 30; i++) {
		a[i].capacidadHab = 2;
		a[i].tipo_hab = 'D';
		a[i].libre = 'L';
	}
	//10 hab triples
	for (i = 30; i < 40; i++) {
		a[i].capacidadHab = 3;
		a[i].tipo_hab = 'T';
		a[i].libre = 'L';
	}
	//10 hab cuadruples
	for (i = 40; i < 50; i++) {
		a[i].capacidadHab = 4;
		a[i].tipo_hab = 'C';
		a[i].libre = 'L';
	}



}
void ReservaHabitacion(struct habitacion* a) {
	int personas;
	int n_habitacion = 0;
	int i;
	do {
		printf("Introduzca numero de personas:");
		scanf_s("%d", &personas);
		switch (personas) {
		case 1:

			i = 0;
			for (i = 0; i < 10; i++) {
				if (a[i].libre == 'L')
					break;
			}

			if (i == 10) {
				printf("No hay habitaciones simples disponibles:");
				printf("Si desea reservar una doble vuelva al menu.");
				menu(a);

			}
			else CompletarDatosHab(a, i);


			break;

		case 2:
			i = 10;
			while (a[i].libre == 'O' || i < 30) {
				i++;
			}
			if (i == 29) {
				printf("No hay habitaciones dobles disponibles:");
				printf("Si desea reservar una triple vuelva al menu.");
				menu(a);

			}
			else CompletarDatosHab(a, i);


			break;

		case 3:
			i = 30;
			while (a[i].libre == 'O' || i < 40) {
				i++;
			}
			if (i == 39) {
				printf("No hay habitaciones triples disponibles:");
				printf("Si desea reservar una cuadruple vuelva al menu.");
				menu(a);

			}
			else CompletarDatosHab(a, i);


			break;

		case 4:
			i = 40;
			while (a[i].libre == 'O' || i < 50) {
				i++;
			}
			if (i == 49) {
				printf("No hay habitaciones cuadruples disponibles:");
				printf("Si desea reservar otra habitacion vuelva al menu.");
				menu(a);

			}
			else CompletarDatosHab(a, i);



			break;

		default: printf("Numero no valido de personas.");
		}
	} while (personas < 0 || personas>4);

}
void CompletarDatosHab(struct habitacion* a, int i) {
	getchar();
	printf("%cCu%cl ser%c su d%ca de llegada?\n", 168, 160, 160, 161);
	gets_s(a[i].fecha);
	getchar();
	printf("%cCu%cnto  durar%c su estancia en noches?\n", 168, 160, 160);
	scanf_s("%d", &a[i].n_dias);
	

	printf("%cNecesitar%c parking?\t Responda con S para si o N para no.\n", 168, 160);
	do
	scanf_s("%c", &a[i].parking);
	
	while 
	(a[i].parking != 's' && a[i].parking != 'S' && a[i].parking != 'n' && a[i].parking != 'N');

	printf("Escriba su nombre\n");
	gets_s(a[i].nombre);
	getchar();
	printf("Escriba su apellido\n");
	gets_s(a[i].apellido);
	getchar();
	printf("Escriba su n%cmero de tel%cfono\n", 163, 130);
	gets_s(a[i].telefono);
	getchar();

}
