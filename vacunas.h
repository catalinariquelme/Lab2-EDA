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


int esListaVaciaVacunas(nodoVacunas* lista){
  if (lista == NULL)
    return 1;
  else
    return 0;
}
/*
Entradas:
Salida: int (semanas)
Objetivo: dado determinado id calcula cuantas semanas necesita para la segunda dosis
*/
int recorrerBuscarSemanas(nodoVacunas* lista,char* id){
  if (!esListaVaciaVacunas(lista)){
    nodoVacunas* auxiliar=lista;
    while (auxiliar!=NULL){
      if (auxiliar->vacunas.numero == id )
        return(auxiliar->vacunas.periodo);
      auxiliar=auxiliar->siguiente;
    }
  }
}