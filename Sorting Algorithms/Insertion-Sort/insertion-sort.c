#include "stdio.h"
#include "stdlib.h"

void showMenu() {
	printf("===========================\n");
	printf("===   INSERTION SORT  =====\n");
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

void insertionSort(int* array, int numbersCount) {

	int candidate;
	int rightArrow, leftArrow, pivot;
	for (pivot = 1; pivot < numbersCount; pivot++)
	{
		printArray(array, numbersCount);
		candidate = array[pivot];
		leftArrow = pivot - 1;
		rightArrow = pivot;
		while (leftArrow >= 0 && array[leftArrow] > candidate)
		{
			rightArrow = leftArrow + 1;
    	array[rightArrow] = array[leftArrow];
    	leftArrow--;
		}
		array[rightArrow - 1] = candidate;
	}
	printArray(array, numbersCount);

}


int main(int argc, char* argv[]){
	int numbersCount;
	int* array;
	int inputNumber;

	showMenu();
	numbersCount = argc - 1; // Removes the name of the program argument
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}
	insertionSort(array, numbersCount);
	
}
