/*Binary Search, arr, ordenado*/
/*si encunetra el numero en el arreglo ordenado, lo regresa;
si no regresa un -1*/

int binarySearch(int[] arr, int tam, int elem){

	int inicio = 0;
	int final = tam - 1;
	int mitad;

	while(inicio <= final){
		 mitad = (inicio + final) / 2;

		 if(arr[mitad] == elem)
		 	return mitad;

		 else if( a[mitad] < elem)
		 	inicio = mitad + 1;

		 else
		 	final = mitad - 1;
	}

	return -1;
}