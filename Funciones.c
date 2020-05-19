
#include "Funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu()
{
	int option = 1;
	int promedio = 0;
	Cliente listaClientes[MAX_CLIENTES];
	Mascotas listaMascotas[MAX_MASCOTAS];
	Raza listaRazas[MAX_RAZAS];
	initRazas(listaRazas, MAX_RAZAS);
	harcodearRazas(listaRazas, MAX_RAZAS);
	initClientes(listaClientes, MAX_CLIENTES);
	hardCodearClientes(listaClientes);
	initMascotas(listaMascotas, MAX_MASCOTAS);
	hardcodearMascotas(listaMascotas);
	initCantidad(listaClientes, listaMascotas, MAX_CLIENTES, MAX_MASCOTAS);
	while (option != 0)
	{
		mifflush();
		system("cls");
		printf("Bienvenido!\n");
		printf("1. Listar todos los clientes con sus mascotas.\n");
		printf("2. Alta mascota\n");
		printf("3. Baja mascota\n");
		printf("4. Modificar mascota\n");
		printf("5. Alta cliente\n");
		printf("6. Baja cliente\n");
		printf("7. Modificar cliente\n");
		printf("8. Ordenar por tipo y listar\n");
		printf("9. Listar clientes con + d una mascota\n");
		printf("10. Listar mascotas adultas\n");
		printf("11. Ordenar por cantidad de mascotas\n");
		printf("12. Ordenar por cantidad de mascotas y nombre\n");
		printf("13. Promedio edad mascotas\n");
		printf("14. Promedio edad mascotas por tipo\n");
		printf("15. Porcentaje de mujeres y varones\n");
		printf("16. Listar clientes\n");
		printf("17. Listar mascotas\n");
		printf("18. Listar cleintes con mascotas del mismo sexo\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			listarClientesConMascotas(listaClientes, listaMascotas, MAX_CLIENTES, MAX_MASCOTAS);
			break;
		case 2:
			altaMascota(listaClientes, listaMascotas, listaRazas, MAX_MASCOTAS, MAX_RAZAS);
			break;
		case 3:
			bajaMascota(listaMascotas, MAX_MASCOTAS);
			break;
		case 4:
			modificarMascota(listaMascotas, listaClientes, MAX_MASCOTAS, MAX_CLIENTES);
			break;
		case 5:
			altaCliente(listaClientes, MAX_CLIENTES);
			break;
		case 6:
			bajaCliente(listaClientes, listaMascotas, MAX_MASCOTAS, MAX_CLIENTES);
			break;
		case 7:
			modificarCliente(listaClientes, MAX_CLIENTES);
			break;
		case 8:
			ordenarPorTipo(listaMascotas, MAX_MASCOTAS);
			break;
		case 9:
			listaClientesMasDeUnaMascota(listaClientes, listaMascotas, MAX_CLIENTES);
			break;
		case 10:
			listaMascotasAdultas(listaClientes, listaMascotas, MAX_CLIENTES, MAX_MASCOTAS);
			break;
		case 11:
			ordenarPorCantMascotas(listaClientes, MAX_CLIENTES);
			break;
		case 12:
			ordenarPorCantMascotasyNombre(listaClientes, MAX_CLIENTES);
			break;
		case 13:
			promedioEdad(listaMascotas, MAX_MASCOTAS);
			break;
		case 14:
			promedioEdadPorTipo(listaMascotas, MAX_MASCOTAS);
			break;
		case 15:
			porcentajeMujeresVarones(listaClientes, MAX_CLIENTES);
			break;
		case 16:
			listarClientes(listaClientes, MAX_CLIENTES);
			break;
		case 17:
			listarMascotas2(listaMascotas, MAX_MASCOTAS);
			break;
		case 18:
			listarMascotasMismoSexo(listaClientes, listaMascotas, MAX_MASCOTAS, MAX_CLIENTES);
			break;
		}
	}
}

void initCantidad(Cliente* list, Mascotas* mascotasList, int len, int mascotasLen)
{
	int contador[MAX_CLIENTES];
	for (int k = 0; k < len; k++)
	{
		contador[k] = 0;
	}
	for (int i = 0; i < len; i++)
	{
		if (!list[i].isEmpty)
		{
			for (int j = 0; j < mascotasLen; j++)
			{
				if (list[i].id == mascotasList[j].idCliente)
				{
					contador[i]++;
				}
			}
			list[i].cantMascotas = contador[i];
		}
	}
}

void listarClientesConMascotas(Cliente* list, Mascotas* mascotasList, int len, int mascotasLen)
{
	char tipoMascota[15];
	system("cls");
	for (int i = 0; i < len; i++)
	{
		if(!list[i].isEmpty)
		{
			printf("--------------------------------------------------------------------------------------\n");
			printf("Nombre\tApellido Localidad\tTelefono\tEdad\tSexo\n");
			printf("%s\t%s \t %s\t\t%d\t\t%d\t%c\n", list[i].nombre, list[i].apellido, list[i].localidad, list[i].telefono, list[i].edad, list[i].sexo);
			printf("\tNombre\t\tTipo\t\tRaza\t\tEdad\tPeso\tSexo\n");
		}
		for (int j = 0; j < mascotasLen; j++)
		{
			switch (mascotasList[j].tipo)
			{
			case 0:
				strcpy(tipoMascota, "Gato");
				break;
			case 1:
				strcpy(tipoMascota, "Perro");
				break;
			case 2:
				strcpy(tipoMascota, "Raro");
			}
			if (mascotasList[j].idCliente == list[i].id)
			{
				if (!mascotasList[j].isEmpty)
				{
					printf("\t%s\t\t%s\t\t%s\t\t%d\t%d\t%c\n", mascotasList[j].nombre, tipoMascota, mascotasList[j].raza, mascotasList[j].edad, mascotasList[j].peso, mascotasList[j].sexo);
				}
			}
		}
	}
	system("pause");
}

void altaMascota(Cliente* list, Mascotas* mascotasList, Raza* razaList, int mascotasLen, int razaLen)
{
	system("cls");
	int id = 0;
	int flag = 1;
	for (int i = 1; i < mascotasLen; i++)
	{
		if (mascotasList[i].isEmpty && flag == 1)
		{
			id = mascotasList[i].idMascota;
			flag = 0;
		}
	}
	printf("Cargar mascota ID #%d \n", id);
	mifflush();
	printf("\nNombre: ");
	gets(mascotasList[id].nombre);
	printf("\nTipo (0 es gato, 1 es perro, 2 es otro): ");
	scanf("%d", &mascotasList[id].tipo);
	mifflush();
	printf("\nEdad: ");
	scanf("%d", &mascotasList[id].edad);
	printf("\nPeso: ");
	scanf("%d", &mascotasList[id].peso);
	mifflush();
	printf("\nSexo (m -> male, f-> female)");
	scanf("%c", &mascotasList[id].sexo);
	listarClientesConId(list, MAX_CLIENTES);
	printf("\nElegir due�o (escribir ID): \n");
	mifflush();
	scanf("%d", &mascotasList[id].idCliente);
	mascotasList[id].isEmpty = 0;
	listarRazasConId(razaList, razaLen);
	printf("\nElegir raza (escribir ID): \n");
	scanf("%d", &mascotasList[id].idRaza);
	printf("La mascota ha sido agregada.\n");
	system("pause");
}

void mifflush()
{
	while (getchar() != '\n');
}

void bajaCliente(Cliente* list, Mascotas* mascotasList, int mascotasLen, int len)
{
	system("cls");
	int id = 0;
	int i = 0;
	int flag = 0;
	char conf = 0;
	listarClientesConId(list, len);
	printf("\n Que cliente desea eliminar? ");
	scanf("%d", &id);
	mifflush();
	printf("Esta seguro que desea eliminar al cliente ID #%d??? Escriba 'S' para confirmar: ", id);
	scanf("%c", &conf);
	if (conf != 's' && conf != 'S')
	{
		printf("La eliminaci�n fue abortada.\n");
		system("pause");
		return 0;
	}
	else
	{
		for (i = 0; i < mascotasLen; i++)
		{
			if (id == mascotasList[i].idCliente)
			{
				mascotasList[i].isEmpty = 1;
			}
		}
		list[id].isEmpty = 1;
	}
}

void ordenarPorTipo(Mascotas* mascotasList, int mascotasLen)
{
	int i;
	int j;
	Mascotas aux;
	
	for (i = 0; i < mascotasLen; i++)
	{
		for (j = i + 1; j < mascotasLen; j++)
		{
			if (mascotasList[i].tipo < mascotasList[j].tipo)
			{
				aux = mascotasList[i];
				mascotasList[i] = mascotasList[j];
				mascotasList[j] = aux;
			}
		}
	}
	system("cls");
	listarMascotas(mascotasList, MAX_MASCOTAS);
	system("pause");
}

void listaClientesMasDeUnaMascota(Cliente* list, Mascotas* mascotasList, int len)
{
	system("cls");
	printf("\nNombre\tMascotas");
	for (int i = 0; i < len; i++)
	{
		if (list[i].cantMascotas > 1)
		{
			printf("\n%s\t%d\n", list[i].nombre, list[i].cantMascotas);
		}
	}
	system("pause");
}

void listaMascotasAdultas(Cliente* list, Mascotas* mascotasList, int len, int mascotasLen)
{
	system("cls");
	int aux = 0;
	printf("Nombre M.\tEdad\tNombre D.");
	for (int i = 0; i < mascotasLen; i++)
	{
		int flag = 0;
		int j = 0;
		if (mascotasList[i].edad > 3)
		{
			while (j < len && !flag)
			{
				if (list[j].id != mascotasList[i].idCliente)
				{
					j++;
				}
				else
				{
					printf("\n%s\t\t%d\t%s", mascotasList[i].nombre, mascotasList[i].edad, list[j].nombre);
					flag = 1;
				}
			}
		}
	}
	system("pause");
}

void modificarMascota(Mascotas* mascotasList, Cliente* list, int mascotasLen, int len)
{
	system("cls");
	int id = 0;
	int j = 0;
	int flag = 0;
	int opcionTipo = 0;
	char nombreCliente[51];
	listarMascotas(mascotasList, MAX_MASCOTAS);
	printf("Que mascota desea modificar? ");
	scanf("%d", &id);
	while (j < mascotasLen && !flag)
	{
		if (id == mascotasList[j].idMascota)
		{
			if (mascotasList[j].isEmpty == 1)
			{
				flag++;
			}
			else
			{
				break;
			}
		}
		else
		{
			j++;
		}
	}
	if (flag == 1)
	{
		printf("La mascota no ha sido encontrada");
		system("pause");
	}
	else
	{
		int opcionMascota = -1;
		while (opcionMascota != 0)
		{
			char tipoMascota[15];
			switch (mascotasList[id].tipo)
			{
			case 0:
				strcpy(tipoMascota, "Gato");
				break;
			case 1:
				strcpy(tipoMascota, "Perro");
				break;
			case 2:
				strcpy(tipoMascota, "Raro");
				break;
			}
			for (int k = 0; k < len; k++)
			{
				if (list[k].id == mascotasList[id].idCliente)
				{
					strcpy(nombreCliente, list[k].nombre);
				}
			}
			system("cls");
			mifflush();
			printf("Que desea modificar de esta mascota? ");
			printf("\n1: Nombre - %s\n", mascotasList[id].nombre);
			printf("2: Tipo - %s\n", tipoMascota);
			printf("3: Raza - %s\n", mascotasList[id].raza);
			printf("4: Edad - %d\n", mascotasList[id].edad);
			printf("5: Peso - %d\n", mascotasList[id].peso);
			printf("6: Sexo - %c\n", mascotasList[id].sexo);
			printf("7: Dueno - %s\n", nombreCliente);
			printf("\nEscriba 0 para regresar al men� principal:  ");
			scanf("%d", &opcionMascota);
			switch (opcionMascota)
			{
			case 1:
				mifflush();
				printf("Escriba el nuevo nombre: ");
				gets(mascotasList[id].nombre);
				break;
			case 2:
				mifflush();
				printf("Escriba el nuevo tipo (0 -> gato, 1 -> perro, 2 -> otro).");
				scanf("%d", &opcionTipo);
				mascotasList[id].tipo = opcionTipo;
				break;
			case 3:
				mifflush();
				printf("Escriba raza del animal: ");
				gets(mascotasList[id].raza);
				break;
			case 4:
				mifflush();
				printf("Escriba la edad del animal: ");
				scanf("%d", &mascotasList[id].edad);
				break;
			case 5:
				mifflush();
				printf("Escriba el peso del animal: ");
				scanf("%d", &mascotasList[id].peso);
				break;
			case 6:
				mifflush();
				printf("Escriba el sexo del animal (m Masculino y f para Femenino)");
				scanf("%c", &mascotasList[id].sexo);
				break;
			case 7:
				mifflush();
				printf("Elija el nuevo cliente: ");
				listarClientesConId(list, len);
				scanf("%d", &mascotasList[id].idCliente);
			}
		}
	}
}

void listarMascotasMismoSexo(Cliente* list, Mascotas* mascotasList, int mascotasLen, int len)
{
	int contadorMasculino[MAX_CLIENTES];
	int contadorFemenino[MAX_CLIENTES];
	printf("Nombre\tCant m\n");
	for (int j = 0; j < len; j++)
	{
		contadorMasculino[j] = 0;
		contadorFemenino[j] = 0;
		for (int k = 0; k < mascotasLen; k++)
		{
			if (mascotasList[k].sexo == 'f' || mascotasList[k].sexo == 'F')
			{
				contadorFemenino[j]++;
			}
			else
			{
				contadorMasculino[j]++;
			}
		}
		if (contadorFemenino[j] == list[j].cantMascotas || contadorMasculino[j] == list[j].cantMascotas)
		{
			printf("%s\t%d\n", list[j].nombre, list[j].cantMascotas);
		}
	}
	system("pause");
}