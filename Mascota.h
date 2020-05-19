#define MAX_MASCOTAS 20

struct
{
	char nombre[50];
	int tipo; //0 -> gato, 1 -> perro, 2 -> otro
	char raza[50];
	int edad;
	int peso;
	char sexo;
	int idCliente;
	int idMascota;
	int isEmpty;
	int idRaza;
} typedef Mascotas;

void initMascotas(Mascotas* mascotasList, int mascotasLen);
void hardcodearMascotas(Mascotas* mascotasList);
void bajaMascota(Mascotas* mascotasList, int mascotasLen);
void listarMascotas(Mascotas* mascotasList, int mascotasLen);
void promedioEdad(Mascotas* mascotasList, int mascotasLen);
void promedioEdadPorTipo(Mascotas* mascotasList, int mascotasLen);
void listarMascotas2(Mascotas* mascotasList, int mascotasLen);