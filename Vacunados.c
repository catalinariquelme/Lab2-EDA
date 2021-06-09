#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vacunados1D.h"
#include "vacunados2D.h"
#include "vacunas.h"

time_t mktime(struct tm *timeptr);

typedef struct date{
  int day;
  int month;
  int year;
}date;

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

date convertirFecha(char* date){
  //char date2[] = "05/04/21";
  printf("Entre a fechas\n");
  char delimitador[] = " / ";
  int fecha[3];
  printf("4\n");
  char* token = NULL;
  printf("4.5");
  token = strtok(date, delimitador);
  printf("5\n");
  int i = 0;
  if(token != NULL){
      while(token != NULL){
          int aux = atoi(token);
          fecha[i] = aux;
          token = strtok(NULL, delimitador);
          i++;
      }
  }
  return fecha;
}

//BubbleSort
/*
void ordenCronologico(struct nodo1D *inicio){
    printf("Entre\n");
    int swapped, i;
    struct nodo1D *nodo1;
    struct nodo1D *nodo2 = NULL;
  
    if (inicio == NULL)
      return;

    do{
      printf("Hola\n");
      swapped = 0;
      nodo1 = inicio;
      while (nodo1->siguiente != nodo2){
        printf("2 while\n");
        int fecha1 = convertirFecha(nodo1->vacunados1D.fecha1dosis,1);
        int fecha2 = convertirFecha(nodo1->siguiente->vacunados1D.fecha1dosis,2);
        printf("Pase fechas\n");
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
*/
void ordenAbecedarioNombre(nodo1D *inicio){
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

void ordenAbecedarioApellido(nodo1D *inicio){
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

/*
Entradas: date fecha(fecha inicial)
Salida: date fecha(fecha tras determinado tiempo)
Objetivo: calcular la fecha tras n semanas
*/
int proximaVacuna(date fecha,int semanas){
   int ret;
   struct tm info;
   char buffer[80];

   info.tm_year = fecha.year - 1900;
   info.tm_mon = fecha.month ;
   info.tm_mday = fecha.day + (semanas*7);
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 0;
   info.tm_isdst = 0;

   ret = mktime(&info);
   if( ret == -1 ) {
      printf("Error: mktime\n");
   } else {
      strftime(buffer, sizeof(buffer), "%c", &info );
      return(buffer);
   }

}

void salidaListado(nodo1D * lista, nodoVacunas* vacunas){
  FILE* arch;
  arch = fopen("listado.out","w");
  if (!esListaVacia1D(lista)){
    nodo1D* auxiliar=lista;
    while (auxiliar!=NULL){
      fputs(auxiliar->vacunados1D.rut,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.nombre,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.apellido,arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.edad,arch);
      fputs(" ",arch);
      int semanas = recorrerBuscarSemanas(vacunas,auxiliar->vacunados1D.idVacuna);
      date fechaInicial = convertirFecha(auxiliar->vacunados1D.fecha1dosis);
      fputs(proximaVacuna(fechaInicial,semanas),arch);
      fputs(" ",arch);
      fputs(auxiliar->vacunados1D.idVacuna,arch);
      fputs("\n",arch);
      auxiliar=auxiliar->siguiente;
    }
  }
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
  //recorrerLista1D(vacunados1D);
  //ordenCronologico(vacunados1D);

  recorrerLista1D(vacunados1D);
  ordenAbecedarioNombre(vacunados1D);
  printf("---------------Alba--------------\n");
  recorrerLista1D(vacunados1D);
  salidaListado(vacunados1D);
  printf("--------------Imprimi-------------\n");
  struct date fechaa;
  fechaa.day = 8;
  fechaa.month = 6;
  fechaa.year = 2021;

  int semanas = 10;
  //proximaVacuna(fechaa,semanas);


  
  return 0;
}


