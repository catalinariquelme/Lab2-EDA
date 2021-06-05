#include <stdio.h>
#include <stdlib.h>

struct vacunados2dosis;

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
