#include "Cliente.h"

void initClientes(Cliente* list, int len) //Funcion para igualar isEmpty a 1 de acuerdo al espacio disponible en el #define
{
	for (int i = 0; i < len; i++)
	{
		list[i].isEmpty = 1;
		list[i].id = i;
		list[i].cantMascotas = 0;
	}
}

void hardCodearClientes(Cliente* list) //Funcion para clientes harcodeados
{
	strcpy(list[0].nombre, "Ana");
	strcpy(list[0].apellido, "Lopez");
	strcpy(list[0].localidad, "Asia");
	list[0].telefono = 152398;
	list[0].edad = 48;
	list[0].sexo = 'F';

	strcpy(list[1].nombre, "Pepe");
	strcpy(list[1].apellido, "Carlos");
	strcpy(list[1].localidad, "Catay");
	list[1].telefono = 157398;
	list[1].edad = 66;
	list[1].sexo = 'M';

	strcpy(list[2].nombre, "Juana");
	strcpy(list[2].apellido, "Marta");
	strcpy(list[2].localidad, "Tigre");
	list[2].telefono = 151298;
	list[2].edad = 18;
	list[2].sexo = 'F';

	strcpy(list[3].nombre, "Juan");
	strcpy(list[3].apellido, "Pedro");
	strcpy(list[3].localidad, "Chaco");
	list[3].telefono = 155801;
	list[3].edad = 20;
	list[3].sexo = 'M';

	strcpy(list[4].nombre, "Mario");
	strcpy(list[4].apellido, "Juan");
	strcpy(list[4].localidad, "Lanus");
	list[4].telefono = 159382;
	list[4].edad = 64;
	list[4].sexo = 'M';

	for (int i = 0; i <= 4; i++)
	{
		list[i].isEmpty = 0;
	}
}

void listarClientesConId(Cliente* list, int len)
{
	printf("ID\tNombre\tApellido\n");
	for (int i = 0; i < MAX_CLIENTES; i++)
	{
		if(!list[i].isEmpty)
		{
		printf("%d\t%s\t%s\n", list[i].id, list[i].nombre, list[i].apellido);
		}
	}
}

void altaCliente(Cliente* list, int len)
{
	system("cls");
	int i = 0;
	int flag = 0;
	int id = 0;
	while (i < MAX_CLIENTES && !flag)
	{
		if (list[i].isEmpty == 1)
		{
			flag++;
			id = list[i].id;
		}
		i++;
	}
	mifflush();
	printf("--- CLIENTE ID #%d ---", list[id].id);
	printf("\nEscribir nombre de cliente: ");
	gets(list[id].nombre);
	printf("\nEscribir apellido de cliente: ");
	gets(list[id].apellido);
	printf("\nEscribir localidad de cliente: ");
	gets(list[id].localidad);
	printf("\nEscribir telefono de cliente: ");
	scanf("%d", &list[id].telefono);
	printf("\nEscribir edad de cliente: ");
	scanf("%d", &list[id].edad);
	mifflush();
	printf("\nEscribir sexo de cliente (M masculino y F femenino): ");
	scanf("%c", &list[id].sexo);
	list[id].isEmpty = 0;
}

void modificarCliente(Cliente* list, int len)
{
	system("cls");
	int id = 0;
	int j = 0;
	int flag = 0;
	int opcionCliente = 1;
	listarClientesConId(list, len);
	printf("Que cliente desea modificar? \n");
	scanf("%d", &id);
	while (j < len && !flag)
	{
		if (id == list[j].id)
		{
			if (list[j].isEmpty == 1)
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
		printf("El cliente no ha sido encontrado");
		system("pause");
	}
	else
	{
		while(opcionCliente != 0)
		{
			printf("\n1. %s", list[id].nombre);
			printf("\n2. %s", list[id].apellido);
			printf("\n3. %s", list[id].localidad);
			printf("\n4. %d", list[id].telefono);
			printf("\n5. %d", list[id].edad);
			printf("\n6. %c", list[id].sexo);
			printf("\nEscriba 0 para volver al menu principal.\n");
			scanf("%d", &opcionCliente);
			switch (opcionCliente)
			{
			case 1:
				mifflush();
				printf("Escriba el nuevo nombre: ");
				gets(list[id].nombre);
				break;
			case 2:
				mifflush();
				printf("Escriba el nuevo apellido: ");
				gets(list[id].apellido);
				break;
			case 3:
				mifflush();
				printf("Escriba la nueva localidad: ");
				gets(list[id].localidad);
				break;
			case 4:
				mifflush();
				printf("Escriba el nuevo telefono: ");
				scanf("%d", &list[id].telefono);
				break;
			case 5:
				mifflush();
				printf("Escriba la nueva edad: ");
				scanf("%d", &list[id].edad);
				break;
			case 6:
				mifflush();
				printf("Escriba el nuevo sexo (M para masculino; F para femenino): ");
				scanf("%c", &list[id].sexo);
				break;
			}
		}
	}
}

void ordenarPorCantMascotas(Cliente* list, int len)
{
	Cliente aux;
	system("cls");
	printf("\nNombre\tMascotas\n");
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (list[i].cantMascotas < list[j].cantMascotas)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}
	for (int k = 0; k < len; k++)
	{
		if (!list[k].isEmpty)
		printf("%s\t%d\n", list[k].nombre, list[k].cantMascotas);
	}
	system("pause");
	system("cls");
}

void ordenarPorCantMascotasyNombre(Cliente* list, int len)
{
	Cliente aux;
	system("cls");
	printf("\nNombre\tMascotas\n");
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (list[i].cantMascotas == list[j].cantMascotas)
			{
				if (strcmp(list[i].nombre, list[j].nombre) > 0)
				{
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}
			}
			else
			{
				if (list[i].cantMascotas < list[j].cantMascotas)
				{
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}
			}
		}
	}
	for (int k = 0; k < len; k++)
	{
		if (!list[k].isEmpty)
		printf("%s\t%d\n", list[k].nombre, list[k].cantMascotas);
	}
	system("pause");
	system("cls");
}
	
void porcentajeMujeresVarones(Cliente* list, int len)
{
	float cantVarones = 0;
	float cantMujeres = 0;
	float total = 0;
	float promedioMujeres = 0;
	for (int i = 0; i < len; i++)
	{
		if (list[i].sexo == 'm' || list[i].sexo == 'M')
		{
			cantVarones++;
		}
		else
		{
			cantMujeres++;
		}
	}
	total = cantVarones + cantMujeres;
	promedioMujeres = (cantMujeres / total) * 100;
	system("cls");
	printf("El porcentaje de mujeres es %f%\n", promedioMujeres);
	system("pause");
}