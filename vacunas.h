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


/*
Entradas: lista(cabeza de la lista)
Salida: 1|0 (Dependiendo si se encuentra vácia o no)
Objetivo: determina si una lista se encuentra vácia
*/
int esListaVaciaVcunas(nodoVacunas* lista){
  if (lista == NULL)
    return 1;
  else
    return 0;
}

void recorrerListaVacunas(nodoVacunas* lista){
  if (!esListaVaciaVcunas(lista)){
    nodoVacunas* auxiliar=lista;
    while (auxiliar!=NULL){
      printf("numero: %s \n",auxiliar->vacunas.numero);
      printf("nombre: %s \n",auxiliar->vacunas.nombre);
      printf("fabricante: %s \n",auxiliar->vacunas.fabricante);
      printf("Periodo: %s \n\n",auxiliar->vacunas.periodo);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacia\n");
}
/*
Entradas: lista(cabeza de la lista), valor (dato a agregar)
Salida:-
Objetivo: insertar un dato al final de la lista entregada
*/
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