#include <stdio.h>
#include <stdlib.h>

/*

////// ENTRADAS ////// 

-Vacunas
[n]
1)Número
2)Nombre
3)Fabricante
4)Periodo (semanas)

-Vacunados1D (1 dosis)
[n]
1)Rut
2)Nombre
3)Apellido
4)Edad
5)Fecha 1 dosis
6)ID vacuna

-Vacunados2D (2 dosis)
[n]
1)Rut
2)Nombre
3)Apellido
4)Edad
5)Fecha 2 dosis
6)ID vacuna

*/


typedef struct nodoGenerico{
  int dato;
  struct nodoGenerico* siguiente;
}nodo;

typedef struct listaGenerica{
  nodo* inicio;
}TDAlista;


TDAlista* crearListaVacia(){
  TDAlista* lista=(TDAlista*)malloc(sizeof(TDAlista));
  lista->inicio=NULL;
  return lista;
}

int esListaVacia(TDAlista* lista){
  if (lista->inicio == NULL)
    return 1;
  else
    return 0;
}

void recorrerLista(TDAlista* lista){
  if (!esListaVacia(lista)){
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL){
      printf("%d ",auxiliar->dato);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacia\n");
}

void insertarNodoInicio(TDAlista* lista, int valor){
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=valor;
  nuevo->siguiente = lista->inicio;
  lista->inicio=nuevo;
}

void insertarNodoFinal(TDAlista* lista, int valor){
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    nodo* final = lista->inicio;
    nuevo->dato=valor;
    nuevo->siguiente = NULL;
    if (esListaVacia(lista)){
      lista->inicio = nuevo;
      
    }
    else{
      while(final->siguiente != NULL){
          final = final->siguiente;
      }
      
      
      final->siguiente = nuevo;
    }

}

void leerArchivo(char* nombre, char*** data){
    FILE* arch;
    arch = fopen(nombre,"r");
    if(arch == NULL){
        printf("No existe el archivo\n");
        exit(1);
    }
    int i = 0;
    while(feof(arch) == 0){
        char* aux = (char*)malloc(100*sizeof(char));
        char* aux2 = (char*)malloc(100*sizeof(char));
        char* aux3 = (char*)malloc(100*sizeof(char));
        fscanf(arch,"%s %s %s",aux,aux2,aux3);
        data[i][0] = aux;
        data[i][1] = aux2;
        data[i][2] = aux3;
        i++;
    }
    fclose(arch);
}

int main(){


    return 0;
}