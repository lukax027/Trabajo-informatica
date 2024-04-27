#include <stdio.h>
#include <malloc.h>
#define DIM 50

struct habitacion {
	int n_personas;
	char fecha[4];
	int n_dias;
	char tipo_hab;
	char parking;
	char nombre[15];
	char telefono[15];
};
struct restaurante {
	int n_personas, opc, dia;
	char telefono[15];
};

void menu();
void Rhabitacion(struct habitacion*, int);
void Rrestaurante(struct restaurante*, int);



void main()
{

	menu();	//llamada a la funcion menú.
}

void menu() {
	struct habitacion a[DIM];
	struct restaurante r[DIM];

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
			Rhabitacion(a, DIM);

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("¡Que pase un buen dia!");


			break;

		case 2: printf("Ha introducido la opcion 2.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;


		case 3: printf("Ha introducido la opcion 3.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;


		case 4: printf("Ha introducido la opcion 4.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;

		case 5: printf("Ha introducido la opcion 5.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;

		case 6: printf("Ha introducido la opcion 6.\n");

			printf("¿Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("¡Que pase un buen dia!");

			break;

		}

	} while (opc < 0 || opc > 7);

}

void Rhabitacion(habitacion* r, int n) {
	int i;
	for (i = 0; i < 2; i++) {
		printf("Introduzca n%cmero de personas\n", 163);
		scanf_s("%d", &r[i].n_personas);
		printf("N%cmero personas habitaci%cn %d:%d\n", 163, 162, i + 1, r[i].n_personas);
	}
}

void Rrestaurante(restaurante* a, int n) {
	int i;
	for (i = 0; i < 2; i++) {
		printf("Introduzca n%cmero de personas\n", 163);
		scanf_s("%d", &a[i].n_personas);
		printf("N%cmero personas habitaci%cn %d:%d\n", 163, 162, i + 1, a[i].n_personas);
	}
}