#include <stdio.h>
#include <malloc.h>


void menu();



void main()
{
	menu();	//llamada a la funcion men�.
}

void menu() {
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

			printf("�Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("�Que pase un buen dia!");


			break;

		case 2: printf("Ha introducido la opcion 2.\n");

			printf("�Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("�Que pase un buen dia!");

			break;


		case 3: printf("Ha introducido la opcion 3.\n");

			printf("�Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("�Que pase un buen dia!");

			break;


		case 4: printf("Ha introducido la opcion 4.\n");

			printf("�Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("�Que pase un buen dia!");

			break;

		case 5: printf("Ha introducido la opcion 5.\n");

			printf("�Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("�Que pase un buen dia!");

			break;

		case 6: printf("Ha introducido la opcion 6.\n");

			printf("�Desea hacer alguna otra cosa?\n");
			printf("Introduzca 1 para volver al menu o 0 para salir del programa:");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
				menu();
			else
				printf("�Que pase un buen dia!");

			break;

		}

	} while (opc < 0 || opc > 7);

}