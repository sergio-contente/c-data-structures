#include <stdio.h>
#include <stdlib.h>

void showMenu() {
	printf("========================================\n");
	printf("============  SELECTION SORT      ======\n");
	printf("========================================\n");
	printf("****************************************\n");
	printf("========================================\n");
	printf("============   Made by:            =====\n");
	printf("===   Sergio Contente              =====\n");
	printf("========================================\n");
	printf("=== 1) Recursive Insertion Sort    =====\n");
	printf("=== 2) Insertion Sort              =====\n");
	printf("=== 3) Descreasing Insertion Sort  =====\n");
	printf("=== 4) Reverse Insertion Sort      =====\n");
	printf("========================================\n");

}

void printArray(int* array, int numbersCount){
	printf("Array:\n[ ");
	
	for (int i = 0; i < numbersCount; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("]\n");
}

void SelectionSort(int* array, int numbersCount){
	int leftArrow, rightArrow, min, temporary;
	for (leftArrow = 0; leftArrow < numbersCount; leftArrow++)
	{
		min = leftArrow;
		for (rightArrow = leftArrow + 1; rightArrow < numbersCount; rightArrow++)
		{
			if (array[rightArrow] < array[min])
			{
				min = rightArrow;
			}
		}
			if (min != leftArrow)
			{
				temporary = array[leftArrow];
				array[leftArrow] = array[min];
				array[min] = temporary;
			}
	printArray(array, numbersCount);
	}
}

int main(int argc, char* argv[]) {
	int numbersCount, inputNumber;
	int* array;

	showMenu();

	numbersCount = argc - 1; // Removes the name of the program argument
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}

	SelectionSort(array, numbersCount);
	return 0;
}
