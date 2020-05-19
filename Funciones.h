#include "Mascota.h"
#include "Cliente.h"
#include "Raza.h"

void listarClientesConMascotas(Cliente* list, Mascotas* mascotasList, int len, int mascotasLen);
void menu();
void altaMascota(Cliente* list, Mascotas* mascotasList, Raza* razaList, int mascotasLen, int razaLen);
void mifflush();
void bajaCliente(Cliente* list, Mascotas* mascotasList, int mascotasLen, int len);
void ordenarPorTipo(Mascotas* mascotasList, int mascotasLen);
void listaClientesMasDeUnaMascota(Cliente* list, Mascotas* mascotasList, int len);
void listaMascotasAdultas(Cliente* list, Mascotas* mascotasList, int len, int mascotasLen);
void initCantidad(Cliente* list, Mascotas* mascotasList, int len, int mascotasLen);