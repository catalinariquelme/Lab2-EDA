#include <stdio.h>
#include <stdlib.h>
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
  int numeroVacunados1D = tamanoArchivo("vacunados1D.in");
  vacunados1dosis* vacunados1D =(vacunados1dosis*)malloc(sizeof(vacunados1dosis)*23);
  lecturaVacunados1D("vacunados1D.in",vacunados1D);

  int numeroVacunados2D = tamanoArchivo("vacunados2D.in");
  vacunados2dosis* vacunados2D =(vacunados2dosis*)malloc(sizeof(vacunados2dosis)*8);
  lecturaVacunados2D("vacunados2D.in",vacunados2D);

  int numeroVacunas = tamanoArchivo("vacunas.in");
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


