#define MAX_RAZAS 15

struct
{
	int id;
	char nombre[51];
	int tipoId;
	char pais[51];
	int isEmpty;
} typedef Raza;

void initRazas(Raza* list, int len);
void harcodearRazas(Raza* list, int len);
void listarRazasConId(Raza* list, int len);
void modificarRaza(Raza* list, int len);