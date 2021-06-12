#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vacunados1D.h"
#include "vacunados2D.h"
#include "vacunas.h"

typedef struct provisiones{
  int enero;
  int febrero;
  int marzo;
  int abril;
  int mayo;
  int junio;
  int julio;
  int agosto;
  int septiembre;
  int octubre;
  int noviembre; 
  int diciembre;
  
}provisiones;


time_t mktime(struct tm *timeptr);

/*
Entardas: fecha(fecha a modificar)
Salida: fechaSalida(int*)
Objetivo: convierte de char a int* una fecha
*/
int* convertirFecha(char fecha[80]){
  int* fechaSalida = (int*)malloc(sizeof(int)*3);
  char* token;
  token = strtok(fecha, "/");
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
  return fechaSalida;
}

/*
Entradas: date fecha(fecha inicial)
Salida: date fecha(fecha tras determinado tiempo)
Objetivo: calcular la fecha tras n semanas
*/
int* proximaVacuna(int *fecha,int semanas){
   int ret;
   struct tm info;
   char buffer[80];
   info.tm_year = fecha[2]+2000 - 1900;
   info.tm_mon = fecha[1];
   info.tm_mday = fecha[0] + (semanas*7);
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 0;
   info.tm_isdst = 0;

   ret = mktime(&info);
   int* fechaSalida = (int*)malloc(sizeof(int)*3);
   if( ret == -1 ) {
      printf("Error: mktime\n");
   } else {
      strftime(buffer, sizeof(buffer), "%c", &info );
      fechaSalida = convertirFecha(buffer);
   }
   return fechaSalida;
}

/*
Entardas: char*nombre(nombre del archivo a leer)
Salida: int dimension(tamaño del archivo)
Objetivo: leer y almacenar la primera línea del archivo (dimension)
*/
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

/*
Entardas: nombre(nombre del archivo a leer), lista(cabeza de la lista)
Salida: -
Objetivo: leer y almacenar en una lista enlazada
*/
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

/*
Entardas: nombre(nombre del archivo a leer), lista(cabeza de la lista)
Salida: -
Objetivo: leer y almacenar en una lista enlazada
*/
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
Entardas: nombre(nombre del archivo a leer), lista(cabeza de la lista)
Salida: -
Objetivo: leer y almacenar en una lista enlazada
*/
void lecturaVacunas(char* nombre,nodoVacunas* lista){
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
    vacunas vacunasExistentes;
    char* aux = (char*)malloc(100*sizeof(char));
    char* aux2 = (char*)malloc(100*sizeof(char));
    char* aux3 = (char*)malloc(100*sizeof(char));
    char* aux4 = (char*)malloc(100*sizeof(char));

    fscanf(arch,"%s %s %s %s",aux,aux2,aux3,aux4);
    vacunasExistentes.numero = aux;
    vacunasExistentes.nombre = aux2;
    vacunasExistentes.fabricante = aux3;
    vacunasExistentes.periodo = aux4;
    insertarNodoFinalVacunas(lista,vacunasExistentes);
  }

  fclose(arch);
}

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

/*
Entardas: inicio(cabeza de la lista)
Salida: -
Objetivo: aplica bubblesort sobre una lista con el finde ordenar
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

/*
Entardas: inicio(cabeza de la lista)
Salida: -
Objetivo: aplica bubblesort sobre una lista con el finde ordenar
*/
void ordenAbecedarioApellido(struct nodo1D *inicio){
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
Entradas: nodo2D *inicio(cabeza lista vacunados con dos dosis), nodo1D *inicio(cabeza lista vacunados con una dosis)
Salida: -
Objetivo: escribir .out que contenga las personas que tengan una vacunación completa
*/
void salidaVacunacionCompleta(nodo2D *inicio, nodo1D *inicio1D){
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

        //Se busca si la persona fue vacunada en el mismo recinto con la primera dosis
        nodo1D* inicio2=inicio1D;
        nodo2D* persona=auxiliar;
        if (!esListaVacia1D(inicio1D)){
          nodo1D* auxiliar2=inicio1D;
          while (auxiliar2!=NULL){
            if (strcmp(auxiliar2->vacunados1D.rut,persona->vacunados2D.rut)== 0){
            fputs(auxiliar2->vacunados1D.rut,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.nombre,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.apellido,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.edad,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.fecha1dosis,arch);
            fputs(" ",arch);
            fputs(auxiliar2->vacunados1D.idVacuna,arch);
            fputs("\n",arch);
            break;
            }
            auxiliar2=auxiliar2->siguiente;
          }
        }
        auxiliar=auxiliar->siguiente;
      }
    }
  fclose(arch);
}

provisiones aumentoMes(int mes,provisiones meses){
  if (mes==1){
    meses.enero = meses.enero + 1;
  }
  else if(mes==2){
    meses.febrero = meses.febrero + 1;
  }
  else if(mes==3){
    meses.marzo = meses.marzo + 1;
  }
  else if(mes==4){
    meses.abril = meses.abril + 1;
  }
  else if(mes==5){
    meses.mayo = meses.mayo + 1;
  }
  else if(mes==6){
    meses.junio = meses.junio + 1;
  }
  else if(mes==7){
    meses.julio = meses.julio + 1;
  }
  else if(mes==8){
    meses.agosto = meses.agosto + 1;
  }
  else if(mes==9){
    meses.septiembre = meses.septiembre + 1;
  }
  else if(mes==10){
    meses.octubre = meses.octubre + 1;
  }
  else if(mes==11){
    meses.noviembre = meses.noviembre + 1;
  }
  else if(mes==12){
    meses.diciembre = meses.diciembre +1;
  }
  return meses;
}

void salidaProvisiones(nodo1D *lista){
  provisiones provisiones;
  provisiones.enero = 0;
  provisiones.febrero = 0;
  provisiones.marzo = 0;
  provisiones.abril = 0;
  provisiones.mayo = 0;
  provisiones.junio = 0;
  provisiones.julio = 0;
  provisiones.agosto = 0;
  provisiones.septiembre = 0;
  provisiones.octubre = 0;
  provisiones.noviembre = 0;
  provisiones.diciembre = 0;

  if (!esListaVacia1D(lista)){
    nodo1D* auxiliar=lista;
    //Se recorre la lista que neceseitarán una segunda dosis (vacunados con una dosis)
    while (auxiliar!=NULL){
      int* fecha = (int*)malloc(sizeof(int)*3);
      fecha = convertirFecha(auxiliar->vacunados1D.fecha1dosis);
      int* fechaNueva = (int*)malloc(sizeof(int)*3);
      //Se calcula en que fecha debe ser administrada la segunda dosis 
      //fechaNueva = proximaVacuna(fecha,10);
      //provisiones = aumentoMes(fechaNueva[0],provisiones);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
}



int main(){
  int numeroVacunados1D = tamanoArchivo("vacunados1D.in");
  nodo1D* vacunados1D=(nodo1D*)malloc(sizeof(nodo1D));
  lecturaVacunados1D("vacunados1D.in",vacunados1D);

  int numeroVacunados2D = tamanoArchivo("vacunados2D.in");
  nodo2D* vacunados2D=(nodo2D*)malloc(sizeof(nodo2D));
  lecturaVacunados2D("vacunados2D.in",vacunados2D);

  int numeroVacunas = tamanoArchivo("vacunas.in");
  nodoVacunas* vacunasE=(nodoVacunas*)malloc(sizeof(nodoVacunas));
  lecturaVacunas("vacunas.in",vacunasE);

  printf("\n-----------\n");
  //Se ordenan de manera cornologica la lista vacunados con una dosis (vacunados1D)
  recorrerLista1D(vacunados1D);
  salidaProvisiones(vacunados1D);
  //salidaVacunacionCompleta(vacunados2D,vacunados1D);
  printf("escribi");
  return 0;
}
