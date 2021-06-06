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

nodo2D* crearListaVacia2D(){
  nodo2D* lista=(nodo2D*)malloc(sizeof(nodo2D));
  lista=NULL;
  return lista;
}

int esListaVacia2D(nodo2D* lista){
  if (lista == NULL)
    return 1;
  else
    return 0;
}

void recorrerLista2D(nodo2D* lista){
  if (!esListaVacia2D(lista)){
    nodo2D* auxiliar=lista;
    while (auxiliar!=NULL){
      printf("Rut: %s \n",auxiliar->vacunados2D.rut);
      printf("Nombre: %s \n",auxiliar->vacunados2D.nombre);
      printf("Apellido: %s \n",auxiliar->vacunados2D.apellido);
      printf("Edad: %s \n",auxiliar->vacunados2D.edad);
      printf("Fecha 2 dosis: %s \n",auxiliar->vacunados2D.fecha2dosis);
      printf("Id vacuna: %s \n\n",auxiliar->vacunados2D.idVacuna);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacia\n");
}

void insertarNodoInicio2D(nodo2D* lista, vacunados2dosis valor){
  nodo2D* nuevo=(nodo2D*)malloc(sizeof(nodo2D));
  nuevo->vacunados2D=valor;
  nuevo->siguiente = lista;
  lista=nuevo;
}

void insertarNodoFinal2D(nodo2D* lista, vacunados2dosis valor){
  nodo2D* nuevo=(nodo2D*)malloc(sizeof(nodo2D));
  nodo2D* final = lista;
  nuevo->vacunados2D=valor;
  nuevo->siguiente = NULL;
  if (esListaVacia2D(lista)){
    lista = nuevo;
  }
  else{
    while(final->siguiente != NULL){
      final = final->siguiente;
    }
    final->siguiente = nuevo;
  }
}

//Intercambia hacia donde apunta los punteros del nodo a y b
void intercambio2D(struct nodo2D *a, struct nodo2D *b){
    vacunados2dosis aux;
    aux = a->vacunados2D;
    a->vacunados2D = b->vacunados2D;
    b->vacunados2D = aux;
}
