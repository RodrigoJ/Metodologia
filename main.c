#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>



//---------------------------------Generacion de los arreglos------------------
void ordenado(int array[], int N){
	int i;

	for(i=0; i < N; i++)
		array[i] = i;
}

void ordenadoInverso(int array[], int N){
	int i;

	for(i=0; i < N; i++)
		array[i] = N - 1 - i;
}

void desordenado(int array[], int N){
	int i;

	for(i=0; i < N; i++){
		array[i] = rand()%N;
	}

}

//---------------------------------Algoritmos de Ordenamiento------------------

//------------------------------------------------Estables--------------------

//----------------------------------------------------------Burbuja----------
void burbuja(int array[], int N){
	int i, j, temp;

	for (i = (N - 1); i > 0; i--) {
	    for (j = 1; j <= i; j++) {
	      if (array[j-1] > array[j]) {
	        temp = array[j-1];
	        array[j-1] = array[j];
	        array[j] = temp;
	      }
	    }
	  }
	}


//----------------------------------------------------------Insersion----------
void insercion(int array[], int N) {
	int i, j, indice;

	for (i=1; i<N; i++) {
	   indice = array[i];
	   j = i - 1;
	   while (j >= 0 && array[j] > indice) {
	      array[j+1] = array[j];
	      j = j - 1;
	   array[j+1] = indice;
	   }
	}
}


//-------------------------------Inestables------------------------------------
//-----------------------------------------------quickSort---------------------
int colocar(int array[], int b, int t)
{
    int i;
    int pivote, valor_pivote;
    int temp;

    pivote = b;
    valor_pivote = array[pivote];
    for (i=b+1; i<=t; i++){
        if (array[i] < valor_pivote){
                pivote++;
                temp=array[i];
                array[i]=array[pivote];
                array[pivote]=temp;

        }
    }
    temp=array[b];

    array[b]=array[pivote];
    array[pivote]=temp;
    return pivote;
}

void quickSort(int array[], int b, int t)
{
     int pivote;
     if(b < t){
        pivote=colocar(array, b, t);
        quickSort(array, b, pivote-1);
        quickSort(array, pivote+1, t);
     }
}


//-------------------------------------------------------seleccion------------
void seleccion(int array[], int N) {
   int min,i,j,aux,ban;

   for(i=0 ; i < N-1 ; i++) {
      ban = 0;
      min = i;
      for(j=i+1 ; j < N ; j++) {
         if (array[min] > array[j]){
            min = j;
            ban = 1;
         }
      }
      if(ban) {
    	  aux = array[min];
    	  array[min] = array[i];
    	  array[i] = aux;
      }
   }
}


//--------------------------------------main----------------------------------
int main(){
	int i, N;
	int opcion, error = 0;

	printf("Ingrese cantidad de elementos a ordenar: ");
	scanf("%i", &N);

	int array[N], array_aux[N];

	time_t inicio, final;

//-----------------------------iniciacion del array--------------------------

	while (!error) {
		printf("\n1) Ordenado\n2) Ordenado Inverso\n3) Desordenado\nIngrese su opcion: ");
		scanf("%i", &opcion);


			switch (opcion) {
				case 1: ordenado(array, N);
						error = 1;
						break;
				case 2: desordenado(array, N);
						error = 1;
						break;
				case 3: ordenadoInverso(array, N);
						error = 1;
						break;
				default: printf("\nOpcion no disponible\n");
						break;
			}
	}

//  Si se prueban todos los algoritmos a la vez, descomentar esta linea.
//  Copia el array en array aux para utilizar el mismo array en cada prueba.

	memcpy(array_aux, array, N*sizeof(int));

////-----------------------------Algoritmos Estables----------------------------

	inicio = clock();
	burbuja(array, N);
	final = clock();

	printf("tiempo burbuja: %f\n", difftime(final, inicio)/CLOCKS_PER_SEC);


	memcpy(array, array_aux, N*sizeof(int));
	inicio = clock();
	insercion(array, N);
	final = clock();

	printf("tiempo insercion: %f\n", difftime(final, inicio)/CLOCKS_PER_SEC);

////----------------------------Algoritmos Inestables---------------------------
	memcpy(array, array_aux, N*sizeof(int));
	inicio = clock();
	quickSort(array, 0, N - 1);
	final = clock();

	printf("tiempo quicksort: %f\n", difftime(final, inicio)/CLOCKS_PER_SEC);

	memcpy(array, array_aux, N*sizeof(int));
	inicio = clock();
	seleccion(array, N);
	final = clock();

	printf("tiempo seleccion: %f\n", difftime(final, inicio)/CLOCKS_PER_SEC);

	return 1;
}


