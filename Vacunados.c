#include <stdio.h>
#include <stdlib.h>
#include "nodos.h"


nodo1D* crearListaVacia(){
  nodo1D* lista=(nodo1D*)malloc(sizeof(nodo1D));
  lista=NULL;
  return lista;
}

int esListaVacia(nodo1D* lista){
  if (lista == NULL)
    return 1;
  else
    return 0;
}

void recorrerLista(nodo1D* lista){
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

void insertarNodoInicio(nodo1D* lista, vacunados1dosis valor){
  nodo1D* nuevo=(nodo1D*)malloc(sizeof(nodo1D));
  nuevo->vacunados1D=valor;
  nuevo->siguiente = lista;
  lista=nuevo;
}

void insertarNodoFinal(nodo1D* lista, vacunados1dosis valor){
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

void lecturaVacunados1D(char* nombre,vacunados1dosis* vacunados){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunados1D;
  fscanf(arch,"%d",&cantidadVacunados1D);
  int i =0;
  while(feof(arch) == 0){
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));
    char* aux5 = (char*)malloc(100*sizeof(char));
    char* aux6 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    vacunados[i].rut = aux;
    vacunados[i].nombre = aux2;
    vacunados[i].apellido = aux3;
    vacunados[i].edad = aux4;
    vacunados[i].fecha1dosis = aux5;
    vacunados[i].idVacuna = aux6;
    i++;
  }

  fclose(arch);
}

void lecturaVacunados2D(char* nombre,vacunados2dosis* vacunados){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunados1D;
  fscanf(arch,"%d",&cantidadVacunados1D);
  int i =0;
  while(feof(arch) == 0){
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));
    char* aux5 = (char*)malloc(100*sizeof(char));
    char* aux6 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    vacunados[i].rut = aux;
    vacunados[i].nombre = aux2;
    vacunados[i].apellido = aux3;
    vacunados[i].edad = aux4;
    vacunados[i].fecha2dosis = aux5;
    vacunados[i].idVacuna = aux6;
    i++;
  }

  fclose(arch);
}

void lecturaVacunas(char* nombre,vacunas* vacunas){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunas;
  fscanf(arch,"%d",&cantidadVacunas);
  int i =0;
  while(feof(arch) == 0){
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s",aux,aux2,aux3,aux4);
    vacunas[i].numero = aux;
    vacunas[i].nombre = aux2;
    vacunas[i].fabricante = aux3;
    vacunas[i].periodo = aux4;
    i++;
  }

  fclose(arch);
}


int main(){

  vacunados1dosis* vacunados1D =(vacunados1dosis*)malloc(sizeof(vacunados1dosis)*23);
  lecturaVacunados1D("vacunados1D.in",vacunados1D);

  vacunados2dosis* vacunados2D =(vacunados2dosis*)malloc(sizeof(vacunados2dosis)*8);
  lecturaVacunados2D("vacunados2D.in",vacunados2D);

  vacunas* vacunasE =(vacunas*)malloc(sizeof(vacunas)*3);
  lecturaVacunas("vacunas.in",vacunasE);





  /*
  for(int i=0;i< 20;i++){
    printf("\nRut: %s\n",vacunados1D[i].rut);
    printf("Nombre: %s\n",vacunados1D[i].nombre);
    printf("Apellido: %s\n",vacunados1D[i].apellido);
    printf("Edad: %s\n",vacunados1D[i].edad);
    printf("2dosis: %s\n",vacunados1D[i].fecha1dosis);
    printf("ID Vacuna: %s",vacunados1D[i].idVacuna);
    printf("\n");
  }
  printf("SEGUNDO DOC--------------------\n");
  for(int i=0;i< 7;i++){
    printf("\nRut: %s\n",vacunados2D[i].rut);
    printf("Nombre: %s\n",vacunados2D[i].nombre);
    printf("Apellido: %s\n",vacunados2D[i].apellido);
    printf("Edad: %s\n",vacunados2D[i].edad);
    printf("2dosis: %s\n",vacunados2D[i].fecha2dosis);
    printf("ID Vacuna: %s",vacunados2D[i].idVacuna);
    printf("\n");
  }
  */
    return 0;
}


