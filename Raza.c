#include "Raza.h"

void initRazas(Raza* razaList, int len)
{
	for (int i = 0; i < len; i++)
	{
		razaList[i].id = i;
		razaList[i].isEmpty = 1;
	}
}

void harcodearRazas(Raza* razaList, int len)
{
	strcpy(razaList[0].nombre, "Siames");
	razaList[0].tipoId = 0;
	strcpy(razaList[0].pais, "Siam");

	strcpy(razaList[1].nombre, "Labrado");
	razaList[1].tipoId = 1;
	strcpy(razaList[1].pais, "Canada");

	strcpy(razaList[2].nombre, "Caniche");
	razaList[2].tipoId = 1;
	strcpy(razaList[1].pais, "UK");

	strcpy(razaList[3].nombre, "Ragdoll");
	razaList[3].tipoId = 0;
	strcpy(razaList[3].pais, "USA");

	strcpy(razaList[4].nombre, "Iguana");
	razaList[4].tipoId = 2;
	strcpy(razaList[4].pais, "Todos");

	strcpy(razaList[5].nombre, "Oveja");
	razaList[5].tipoId = 2;
	strcpy(razaList[5].pais, "Todos");

	for (int i = 0; i < 6; i++)
	{
		razaList[i].isEmpty = 0;
	}
}

void listarRazasConId(Raza* razaList, int len)
{
	system("cls");
	printf("ID\tNombre\n");
	for (int i = 0; i < len; i++)
	{
		if(!razaList[i].isEmpty)
		{
			printf("%d\t%s\n", razaList[i].id, razaList[i].nombre);
		}
	}
}