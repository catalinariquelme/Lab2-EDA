#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacunados1D.h"
#include "vacunados2D.h"
#include "vacunas.h"

//Entardas: char*nombre(nombre del archivo a leer)
//Salida: int dimension(tamaño del archivo)
//Objetivo: leer y almacenar la primera línea del archivo (dimension)
int tamanoArchivo(char* nombre){    
    FILE* arch;
    arch = fopen(nombre,"r");
    if(arch == NULL){
        printf("No existe el archivo\n");
        exit(1);
    }
    char* aux = (char*)malloc(100*sizeof(char));
    fgets(aux,100,arch);
    fclose(arch);
    int dimension;
    dimension = atoi(aux);
    return dimension;
}

void lecturaVacunados1D(char* nombre,nodo1D* lista){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunados1D;
  fscanf(arch,"%d",&cantidadVacunados1D);
  while(feof(arch) == 0){
    vacunados1dosis vacunados;
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));
    char* aux5 = (char*)malloc(100*sizeof(char));
    char* aux6 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    vacunados.rut = aux;
    vacunados.nombre = aux2;
    vacunados.apellido = aux3;
    vacunados.edad = aux4;
    vacunados.fecha1dosis = aux5;
    vacunados.idVacuna = aux6;

    insertarNodoFinal1D(lista,vacunados);
  }
  fclose(arch);
}

void lecturaVacunados2D(char* nombre,nodo2D* lista){
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunados2D;
  fscanf(arch,"%d",&cantidadVacunados2D);
  int i =0;
  while(feof(arch) == 0){
    vacunados2dosis vacunados;
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));
    char* aux5 = (char*)malloc(100*sizeof(char));
    char* aux6 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    vacunados.rut = aux;
    vacunados.nombre = aux2;
    vacunados.apellido = aux3;
    vacunados.edad = aux4;
    vacunados.fecha2dosis = aux5;
    vacunados.idVacuna = aux6;

    insertarNodoFinal2D(lista,vacunados);
  }

  fclose(arch);
}

/*
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

//0->día
//1->mes
//2->año
*/
int convertirFecha(char* date,int j){
  //char date[] = "05/04/21";
  char delimitador[] = "/";
  int fecha[3];
  char *token = strtok(date, delimitador);
  int i = 0;
  if(token != NULL){
      while(token != NULL){
          int aux = atoi(token);
          fecha[i] = aux;
          token = strtok(NULL, delimitador);
          i++;
      }
  }
  for ( int i = 0; i < 3; i++){
      printf("%d  ",fecha[i]);
  }
  return fecha[j];
}

//BubbleSort

void ordenCronologico(struct nodo1D *inicio){
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    if (inicio == NULL)
      return;
  
    do{
      swapped = 0;
      nodo1 = inicio;
      while (nodo1->siguiente != nodo2){
        int fecha1 = convertirFecha(nodo1->vacunados1D.fecha1dosis,1);
        int fecha2 = convertirFecha(nodo1->siguiente->vacunados1D.fecha1dosis,2);

        if (fecha1 >fecha2){ 
            intercambio1D(nodo1, nodo1->siguiente);
            swapped = 1;
        }
        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

int main(){
  int numeroVacunados1D = tamanoArchivo("vacunados1D.in");
  nodo1D* vacunados1D=(nodo1D*)malloc(sizeof(nodo1D));
  lecturaVacunados1D("vacunados1D.in",vacunados1D);

  int numeroVacunados2D = tamanoArchivo("vacunados2D.in");
  nodo2D* vacunados2D=(nodo2D*)malloc(sizeof(nodo2D));
  lecturaVacunados2D("vacunados2D.in",vacunados2D);

  /*
  int numeroVacunas = tamanoArchivo("vacunas.in");
  nodoVacunas* vacunasE=(nodoVacunas*)malloc(sizeof(nodoVacunas));
  lecturaVacunas("vacunas.in",vacunasE);
  */

  //Se ordenan de manera cornologica la lista vacunados con una dosis (vacunados1D)
  recorrerLista1D(vacunados1D);
  ordenCronologico(vacunados1D);
  printf("-------CRONOLOGICO--------\n");
  recorrerLista1D(vacunados1D);

  return 0;
}


