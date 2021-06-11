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

int esListaVaciaVcunas(nodoVacunas* lista){
  if (lista == NULL)
    return 1;
  else
    return 0;
}

void insertarNodoFinalVacunas(nodoVacunas* lista, vacunas valor){
  nodoVacunas* nuevo=(nodoVacunas*)malloc(sizeof(nodoVacunas));
  nodoVacunas* final = lista;
  nuevo->vacunas=valor;
  nuevo->siguiente = NULL;
  if (esListaVaciaVcunas(lista)){
    lista = nuevo;
  }
  else{
    while(final->siguiente != NULL){
      final = final->siguiente;
    }
    final->siguiente = nuevo;
  }
}