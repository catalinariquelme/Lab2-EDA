#include <stdio.h>
#include <stdlib.h>

struct vacunas;

typedef struct vacunas{
  char* numero;
  char* nombre;
  char* fabricante;
  char* periodo;
  struct vacunas* siguiente;
}vacunas;

typedef struct nodoVacunas{
  struct vacunas vacunas;
  struct nodoVacunas * siguiente;
}nodoVacunas;

