#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacunados1D.h"
#include "vacunados2D.h"
#include "vacunas.h"

int* convertirFecha(char fecha[80]){
  //printf("Fecha %s\n",fecha);
  int* fechaSalida = (int*)malloc(sizeof(int)*3);
  char* token;
  token = strtok(fecha, "/");
  if (token == NULL){
    printf("Eror fecha\n");
  }
  int i = 0;
  fechaSalida[i] = atoi(token);
  i++;
  while (token!= NULL){
    token = strtok(NULL,"/");
    if (token != NULL){
      fechaSalida[i] = atoi(token);
      i++;
    }
  }
  //printf("Fecha\n");
  for(int i =0;i<3;i++){
    //printf("%d/ ",fechaSalida[i]);
  }
  //printf("\n\n");
  return fechaSalida;
}

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
    char aux5[80];
    char* aux6 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    printf("Fecha %s\n",aux5);
    vacunados.rut = aux;
    vacunados.nombre = aux2;
    vacunados.apellido = aux3;
    vacunados.edad = aux4;
    strcpy(vacunados.fecha1dosis,aux5);
    printf("Fecha %s\n",vacunados.fecha1dosis);
    vacunados.idVacuna = aux6;
    printf("Fecha %s\n",vacunados.fecha1dosis);
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
*/


/*
void bubbleSort(struct nodo1D *start)
{
    int swapped, i;
    struct nodo1D *ptr1 = start;
    struct nodo1D *lptr = NULL;
    printf("-----Fecha = %s\n",ptr1->vacunados1D.fecha1dosis);
    /* Checking for empty list 
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->siguiente != lptr){
          printf("Fecha = %s\n",ptr1->vacunados1D.fecha1dosis);
          int* fecha1 = (int*)malloc(sizeof(int)*3);
          fecha1 = convertirFecha(ptr1->vacunados1D.fecha1dosis);
          int* fecha2 = (int*)malloc(sizeof(int)*3);
          fecha2 = convertirFecha(ptr1->siguiente->vacunados1D.fecha1dosis);

          if (fecha1[1] > fecha2[1]){ 
            intercambio1D(ptr1, ptr1->siguiente);
            swapped = 1;
          }
          ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  

*/






void ordenAbecedarioNombre(struct nodo1D *inicio){
    printf("Entre\n");
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    if (inicio == NULL)
      return;

    do{
      swapped = 0;
      nodo1 = inicio;
      while (nodo1->siguiente != nodo2){
        int ret = strcmp(nodo1->vacunados1D.nombre,nodo1->siguiente->vacunados1D.nombre);
        if (ret>0){ 
            intercambio1D(nodo1, nodo1->siguiente);
            swapped = 1;
        }
        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

void ordenAbecedarioApellido(struct nodo1D *inicio){
    printf("Entre\n");
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    if (inicio == NULL)
      return;

    do{
      swapped = 0;
      nodo1 = inicio;
      while (nodo1->siguiente != nodo2){
        int ret = strcmp(nodo1->vacunados1D.apellido,nodo1->siguiente->vacunados1D.apellido);
        if (ret>0){ 
            intercambio1D(nodo1, nodo1->siguiente);
            swapped = 1;
        }
        nodo1 = nodo1->siguiente;
      }
      nodo2 = nodo1;
  }
  while (swapped);
}

void salidaVacunacionCompleta(nodo2D *inicio){
    FILE* arch;
    arch = fopen("vacunacionCompleta.out","w");
    if (!esListaVacia2D(inicio)){
      nodo2D* auxiliar=inicio;

      while (auxiliar!=NULL){
        fputs(auxiliar->vacunados2D.rut,arch);
        fputs(" ",arch);
        fputs(auxiliar->vacunados2D.nombre,arch);
        fputs(" ",arch);
        fputs(auxiliar->vacunados2D.apellido,arch);
        fputs(" ",arch);
        fputs(auxiliar->vacunados2D.edad,arch);
        fputs(" ",arch);
        fputs(auxiliar->vacunados2D.fecha2dosis,arch);
        fputs(" ",arch);
        fputs(auxiliar->vacunados2D.idVacuna,arch);
        fputs("\n",arch);
        auxiliar=auxiliar->siguiente;
      }
    fclose(arch);
    }
}





int main(){
  int numeroVacunados1D = tamanoArchivo("vacunados1D.in");
  nodo1D* vacunados1D=(nodo1D*)malloc(sizeof(nodo1D));
  lecturaVacunados1D("vacunados1D.in",vacunados1D);
  printf("1d");
  int numeroVacunados2D = tamanoArchivo("vacunados2D.in");
  nodo2D* vacunados2D=(nodo2D*)malloc(sizeof(nodo2D));
  lecturaVacunados2D("vacunados2D.in",vacunados2D);
  printf("2d\n");

  /*
  int numeroVacunas = tamanoArchivo("vacunas.in");
  nodoVacunas* vacunasE=(nodoVacunas*)malloc(sizeof(nodoVacunas));
  lecturaVacunas("vacunas.in",vacunasE);
  */

  //Se ordenan de manera cornologica la lista vacunados con una dosis (vacunados1D)
  recorrerLista1D(vacunados1D);
  //bubbleSort(vacunados1D);
  printf("--------------------------------------------------------------------------------------\n");
  salidaVacunacionCompleta(vacunados2D);
  printf("escribi");
  //recorrerLista1D(vacunados1D);
  //ordenAbecedarioNombre(vacunados1D);
  //printf("---------------Alba--------------\n");
  //recorrerLista1D(vacunados1D);
  return 0;
}


