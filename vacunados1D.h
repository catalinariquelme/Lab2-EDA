#include <stdio.h>
#include <stdlib.h>

struct vacunados1dosis;

typedef struct vacunados1dosis{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char fecha1dosis[80];
  char* idVacuna;
  
}vacunados1dosis;

typedef struct nodo1D{
  struct vacunados1dosis vacunados1D;
  struct nodo1D * siguiente;
}nodo1D;

nodo1D* crearListaVacia1D(){
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
  if (!esListaVacia1D(lista)){
    nodo1D* auxiliar=lista;
    while (auxiliar!=NULL){
      printf("Rut: %s \n",auxiliar->vacunados1D.rut);
      printf("Nombre: %s \n",auxiliar->vacunados1D.nombre);
      printf("Apellido: %s \n",auxiliar->vacunados1D.apellido);
      printf("Edad: %s \n",auxiliar->vacunados1D.edad);
      printf("Fecha 1 dosis: %s\n",auxiliar->vacunados1D.fecha1dosis);
      printf("Id vacuna: %s \n\n",auxiliar->vacunados1D.idVacuna);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacia\n");
}

void insertarNodoFinal1D(nodo1D* lista, vacunados1dosis valor){
  nodo1D* nuevo=(nodo1D*)malloc(sizeof(nodo1D));
  nodo1D* final = lista;
  nuevo->vacunados1D=valor;
  nuevo->siguiente = NULL;
  if (esListaVacia1D(lista)){
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
