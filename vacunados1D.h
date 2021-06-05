#include <stdio.h>
#include <stdlib.h>

struct vacunados1dosis;

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

nodo1D* crearListaVacia(){
  nodo1D* lista=(nodo1D*)malloc(sizeof(nodo1D));
  lista=NULL;
  return lista;
}

int esListaVacia1D(nodo1D* lista){
  if (lista == NULL)
    return 1;
  else
    return 0;
}

void recorrerLista1D(nodo1D* lista){
  if (!esListaVacia(lista)){
    nodo1D* auxiliar=lista;
    while (auxiliar!=NULL){
      printf("%s  ",auxiliar->vacunados1D);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacia\n");
}

void insertarNodoInicio1D(nodo1D* lista, vacunados1dosis valor){
  nodo1D* nuevo=(nodo1D*)malloc(sizeof(nodo1D));
  nuevo->vacunados1D=valor;
  nuevo->siguiente = lista;
  lista=nuevo;
}

void insertarNodoFinal1D(nodo1D* lista, vacunados1dosis valor){
  nodo1D* nuevo=(nodo1D*)malloc(sizeof(nodo1D));
  nodo1D* final = lista;
  nuevo->vacunados1D=valor;
  nuevo->siguiente = NULL;
  if (esListaVacia(lista)){
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
void intercambio1D(struct nodo1D *a, struct nodo1D *b){
    vacunados1dosis aux;
    aux = a->vacunados1D;
    a->vacunados1D = b->vacunados1D;
    b->vacunados1D = aux;
}