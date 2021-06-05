#include <stdio.h>
#include <stdlib.h>

struct vacunados1dosis;
struct vacunados2dosis;
struct vacunas;

typedef struct vacunados1dosis{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char* fecha1dosis;
  char* idVacuna;
}vacunados1dosis;

typedef struct nodo1D{
  struct vacunados1dosis vacunados1D;
  struct nodo1D * siguiente;
}nodo1D;

typedef struct vacunados2dosis{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char* fecha2dosis;
  char* idVacuna;
  struct vacunados2dosis* siguiente;
}vacunados2dosis;

typedef struct nodo2D{
  struct vacunados2dosis vacunados2D;
  struct nodo2D * siguiente;
}nodo2D;

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
