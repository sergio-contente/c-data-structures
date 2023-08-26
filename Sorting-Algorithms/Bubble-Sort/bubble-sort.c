#include <stdio.h>
#include <stdlib.h>

void showMenu() {
	printf("========================================\n");
	printf("============  BUBBLE SORT      =========\n");
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

void BubbleSort(int* array, int numbersCount){
	int bubbles_counter, indexArrow;
	int temporary;
	for (bubbles_counter = 0; bubbles_counter < numbersCount; bubbles_counter++)
	{
		for (indexArrow = 0; indexArrow < numbersCount - bubbles_counter - 1; indexArrow++)
		{
			printArray(array, numbersCount);
			if (array[indexArrow + 1] < array[indexArrow])
			{
				temporary = array[indexArrow + 1];
				array[indexArrow + 1] = array[indexArrow];
				array[indexArrow] = temporary;
			}
		}
	}
	printArray(array, numbersCount);
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

	BubbleSort(array, numbersCount);
	return 0;
}
