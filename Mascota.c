#include "Mascota.h"

void initMascotas(Mascotas* mascotasList, int mascotasLen)
{
	for (int i = 0; i < mascotasLen; i++)
	{
		mascotasList[i].isEmpty = 1;
		mascotasList[i].idMascota = i;
		mascotasList[i].idRaza = 0;
	}
}

void hardcodearMascotas(Mascotas* list)
{

	list[0].idCliente = 0;
	strcpy(list[0].nombre, "Chusen");
	list[0].tipo = 0;
	strcpy(list[0].raza, "Siames");
	list[0].edad = 10;
	list[0].peso = 16;
	list[0].sexo = 'F';


	list[1].idCliente = 0;
	strcpy(list[1].nombre, "Sombra");
	list[1].tipo = 0;
	strcpy(list[1].raza, "Siames");
	list[1].edad = 13;
	list[1].peso = 14;
	list[1].sexo = 'F';

	list[2].idCliente = 1;
	strcpy(list[2].nombre, "Inu");
	list[2].tipo = 1;
	strcpy(list[2].raza, "Labrado");
	list[2].edad = 8;
	list[2].peso = 12;
	list[2].sexo = 'M';

	list[3].idCliente = 1;
	strcpy(list[3].nombre, "Fido");
	list[3].tipo = 1;
	strcpy(list[3].raza, "Caniche");
	list[3].edad = 4;
	list[3].peso = 7;
	list[3].sexo = 'M';

	list[4].idCliente = 1;
	strcpy(list[4].nombre, "Guppy");
	list[4].tipo = 0;
	strcpy(list[4].raza, "Ragdoll");
	list[4].edad = 3;
	list[4].peso = 7;
	list[4].sexo = 'M';

	list[5].idCliente = 2;
	strcpy(list[5].nombre, "Topi");
	list[5].tipo = 1;
	strcpy(list[5].raza, "Pitbull");
	list[5].edad = 7;
	list[5].peso = 19;
	list[5].sexo = 'M';

	list[6].idCliente = 2;
	strcpy(list[6].nombre, "Gex");
	list[6].tipo = 2;
	strcpy(list[6].raza, "N/A");
	list[6].edad = 2;
	list[6].peso = 1;
	list[6].sexo = 'M';

	list[7].idCliente = 3;
	strcpy(list[7].nombre, "Hola");
	list[7].tipo = 1;
	strcpy(list[7].raza, "Labrado");
	list[7].edad = 14;
	list[7].peso = 11;
	list[7].sexo = 'M';

	list[8].idCliente = 4;
	strcpy(list[8].nombre, "Puck");
	list[8].tipo = 0;
	strcpy(list[8].raza, "Bengal");
	list[8].edad = 1;
	list[8].peso = 4;
	list[8].sexo = 'M';

	list[9].idCliente = 4;
	strcpy(list[9].nombre, "Chau");
	list[9].tipo = 0;
	strcpy(list[9].raza, "Persa");
	list[9].edad = 6;
	list[9].peso = 8;
	list[9].sexo = 'F';

	list[10].idCliente = 4;
	strcpy(list[10].nombre, "Bruh");
	list[10].tipo = 1;
	strcpy(list[10].raza, "Bulldog");
	list[10].edad = 11;
	list[10].peso = 11;
	list[10].sexo = 'M';

	for (int i = 0; i < 11; i++)//poniendo el isEmpty de las mascotas harcodeadas en 0
	{
		list[i].isEmpty = 0;
	}
}

void bajaMascota(Mascotas* mascotasList, int mascotasLen)
{
	system("cls");
	int id = 0;
	int flag = 0;
	int i = 0;
	listarMascotas(mascotasList, MAX_MASCOTAS);
	printf("Que mascota desea eliminar? Escriba su ID: ");
	scanf("%d", &id);
	while (i < mascotasLen && !flag)
	{
		if (mascotasList[i].idMascota == id && !mascotasList[i].isEmpty)
		{
			mascotasList[i].isEmpty = 1;
			printf("La mascota ID #%d ha sido eliminada!", id);
			flag = 1;
			system("pause");
		}
		i++;
	}
	if (flag == 0)
	{
		printf("La mascota ID #%d no ha sido encontrada. Reintentelo.\n", id);
		system("pause");
	}
}

void listarMascotas(Mascotas* mascotasList, int mascotasLen)
{
	char tipoMascota[15];
	printf("Id\tNombre\t\tTipo\t\tRaza\t\tEdad\tPeso\tSexo\n");
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
			break;
		}
		if (!mascotasList[j].isEmpty)
		{
			printf("%d\t%s\t\t%s\t\t%s\t\t%d\t%d\t%c\n",mascotasList[j].idMascota, mascotasList[j].nombre, tipoMascota, mascotasList[j].raza, mascotasList[j].edad, mascotasList[j].peso, mascotasList[j].sexo);
		}
	}
}

void modificarMascota(Mascotas* mascotasList, int mascotasLen)
{
	system("cls");
	int id = 0;
	int j = 0;
	int flag = 0;
	int opcionTipo = 0;
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
			system("cls");
			mifflush();
			printf("Que desea modificar de esta mascota? ");
			printf("\n1: Nombre - %s\n", mascotasList[id].nombre);
			printf("2: Tipo - %s\n", tipoMascota);
			printf("3: Raza - %s\n", mascotasList[id].raza);
			printf("4: Edad - %d\n", mascotasList[id].edad);
			printf("5: Peso - %d\n", mascotasList[id].peso);
			printf("6: Sexo - %c\n", mascotasList[id].sexo);
			printf("\nEscriba 0 para regresar al menú principal:  ");
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
			}
		}
	}
}

void promedioEdad(Mascotas* mascotasList, int mascotasLen)
{
	int sumaEdad = 0;
	int contadorMascotas = 0;
	float promedio = 0;
	for (int i = 0; i < mascotasLen; i++)
	{
		if(!mascotasList[i].isEmpty)
		{
			contadorMascotas++;
			sumaEdad = sumaEdad + mascotasList[i].edad;
		}
	}
	promedio = sumaEdad / contadorMascotas;
	system("cls");
	printf("El promedio de edad es %f\n", promedio);
	system("pause");
}

void promedioEdadPorTipo(Mascotas* mascotasList, int mascotasLen)
{
	int sumaEdadGato = 0;
	int sumaEdadPerro = 0;
	int sumaEdadOtro = 0;
	int contadorGato = 0;
	int contadorPerro = 0;
	int contadorOtro = 0;
	float promedioGato = 0;
	float promedioPerro = 0;
	float promedioOtro = 0;

	for (int i = 0; i < mascotasLen; i++)
	{
		if (!mascotasList[i].isEmpty)
		{
			switch (mascotasList[i].tipo)
			{
			case 0:
				contadorGato++;
				sumaEdadGato = sumaEdadGato + mascotasList[i].edad;
				break;
			case 1:
				contadorPerro++;
				sumaEdadPerro = sumaEdadPerro + mascotasList[i].edad;
				break;
			case 2:
				contadorOtro++;
				sumaEdadOtro = sumaEdadOtro + mascotasList[i].edad;
				break;
			}
		}
	}
	promedioGato = sumaEdadGato / contadorGato;
	promedioPerro = sumaEdadPerro / contadorPerro;
	promedioOtro = sumaEdadOtro / contadorOtro;
	system("cls");
	printf("Promedio edad gatos: %f\n", promedioGato);
	printf("Promedio edad perro: %f\n", promedioPerro);
	printf("Promedio edad raros: %f\n", promedioOtro);
	system("pause");
}