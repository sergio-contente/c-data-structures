#include "stdio.h"
#include "stdlib.h"

void showMenu() {
	printf("===========================\n");
	printf("===   MERGE SORT  =====\n");
	printf("===========================\n");
	printf("***************************\n");
	printf("===========================\n");
	printf("===   Made by:        =====\n");
	printf("===   Sergio Contente =====\n");
	printf("===========================\n");
}

void printArray(int* array, int numbersCount){
	printf("Array:\n[ ");
	
	for (int i = 0; i < numbersCount; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("]\n");
}

void getUserArray(int* array, int numbersCount, char* argv[]){
	int inputNumber;
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}
	printArray(array, numbersCount);
}

void merge(int* array, int left, int middle, int right){
	int start_left = left;
	int start_right = middle + 1;
	int start_aux = 0;
	int lenght_aux = right - left + 1;

	int* arrayAux;

	arrayAux = (int*)malloc(lenght_aux * sizeof(int));

	while (start_left <= middle && start_right <= right) {
		if(array[start_left] < array[start_right]){
			arrayAux[start_aux] = array[start_left];
			start_left++;
		} else {
			arrayAux[start_aux] = array[start_right];
			start_right++;
		}
		start_aux++;
	}

	while (start_left <= middle)
	{
		arrayAux[start_aux] = array[start_left];
		start_aux++;
		start_left++;
	}

	while (start_right <= right)
	{
		arrayAux[start_aux] = array[start_right];
		start_aux++;
		start_right;
	}
	
	for(start_aux = left; start_aux <= right; start_aux++) {
		array[start_aux] = arrayAux[start_aux - left];
	}

	printArray(array, lenght_aux);
	free(arrayAux);

}

void mergeSort(int* array, int left, int right) {
	if (left < right)
	{
		int middle = (left+right)/2;

		mergeSort(array, left, middle);
		mergeSort(array, middle+1, right);
		merge(array, left, middle, right);
	}
}

int main(int argc, char* argv[]) {
	int* array;
	int numbersCount = argc - 1; // Removes the name of the program argument;

 	showMenu();
	getUserArray(array, numbersCount, argv);
	mergeSort(array, 0, 4);
	return 0;
}
