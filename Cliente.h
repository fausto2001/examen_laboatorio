#define MAX_CLIENTES 10

struct 
{
	int id;
	char nombre[51];
	char apellido[51];
	char localidad[51];
	int telefono;
	int edad;
	char sexo;
	int isEmpty;
	int cantMascotas;
}typedef Cliente;


void initClientes(Cliente* list, int len);
void hardCodearClientes(Cliente* list);
void listarClientesConId(Cliente* list, int len);
void altaCliente(Cliente* list, int len);
void modificarCliente(Cliente* list, int len);
void ordenarPorCantMascotas(Cliente* list, int len);
void ordenarPorCantMascotasyNombre(Cliente* list, int len);
void porcentajeMujeresVarones(Cliente* list, int len);