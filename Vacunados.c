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

typedef struct vacunados1D{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char* fecha2dosis;
  char* idVacuna;
}vacunados1D;

typedef struct vacunados2D{
  char* rut;
  char* nombre;
  char* apellido;
  char* edad;
  char* fecha2dosis;
  char* idVacuna;
}vacunados2D;




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

void lecturaVacunados1D(char* nombre,vacunados1D* vacunados){
  printf("Hola\n");
  FILE* arch;
  arch = fopen(nombre,"r");
  if(arch == NULL){
      printf("No existe el archivo\n");
      exit(1);
  }
  int cantidadVacunados1D;
  fscanf(arch,"%d",&cantidadVacunados1D);
  printf("Lei cantidad\n");

  char* aux = (char*)malloc(100*sizeof(char));
  char* aux2 = (char*)malloc(100*sizeof(char));
  char* aux3 = (char*)malloc(100*sizeof(char));
  char* aux4 = (char*)malloc(100*sizeof(char));
  char* aux5 = (char*)malloc(100*sizeof(char));
  char* aux6 = (char*)malloc(100*sizeof(char));

  int i =0;
  while(feof(arch) == 0){
    fscanf(arch,"%s %s %s %s %s %s",aux,aux2,aux3,aux4,aux5,aux6);
    vacunados[i].rut = aux;
    vacunados[i].nombre = aux2;
    vacunados[i].apellido = aux3;
    vacunados[i].edad = aux4;
    vacunados[i].fecha2dosis = aux5;
    vacunados[i].idVacuna = aux6;
  }
  printf("Lei la otra basura\n");
  for(int i=0;i< cantidadVacunados1D;i++){
    printf("\nRut: %s\n",vacunados[i].rut);
    printf("Nombre: %s\n",vacunados[i].nombre);
    printf("Apellido: %s\n",vacunados[i].apellido);
    printf("Edad: %s\n",vacunados[i].edad);
    printf("2dosis: %s\n",vacunados[i].fecha2dosis);
    printf("ID Vacuna: %s",vacunados[i].idVacuna);
    printf("\n");
  }
  fclose(arch);
}

int main(){

  vacunados1D* vacunados =(vacunados1D*)malloc(sizeof(vacunados1D)*23);
  printf("Estructura\n");
  lecturaVacunados1D("vacunados1D.in",vacunados);
  printf("Lei\n");


    return 0;
}


