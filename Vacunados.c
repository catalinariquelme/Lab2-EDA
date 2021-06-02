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
  char* dato;
  struct nodoGenerico* siguiente;
}nodo;

typedef struct listaGenerica{
  nodo* inicio;
}TDAlista;

typedef struct vacunados1dosis{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char* fecha1dosis;
  char* idVacuna;
}vacunados1dosis;

typedef struct vacunados2dosis{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char* fecha2dosis;
  char* idVacuna;
}vacunados2dosis;




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
      printf("%s  ",auxiliar->dato);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacia\n");
}

void insertarNodoInicio(TDAlista* lista, char* valor){
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=valor;
  nuevo->siguiente = lista->inicio;
  lista->inicio=nuevo;
}

void insertarNodoFinal(TDAlista* lista, char* valor){
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
int main(){

  vacunados1dosis* vacunados1D =(vacunados1dosis*)malloc(sizeof(vacunados1dosis)*23);
  lecturaVacunados1D("vacunados1D.in",vacunados1D);

  vacunados2dosis* vacunados2D =(vacunados2dosis*)malloc(sizeof(vacunados1dosis)*8);
  lecturaVacunados2D("vacunados2D.in",vacunados2D);


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


