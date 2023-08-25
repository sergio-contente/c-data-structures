#include "stdio.h"
#include "stdlib.h"

void showMenu() {
	printf("========================================\n");
	printf("============  INSERTION SORT   =========\n");
	printf("========================================\n");
	printf("****************************************\n");
	printf("========================================\n");
	printf("============   Made by:            =====\n");
	printf("===   Sergio Contente              =====\n");
	printf("========================================\n");
	printf("=== 1) Insertion Sort              =====\n");
	printf("=== 2) Simple Insertion Sort       =====\n");
	printf("=== 3) Descreasing Insertion Sort  =====\n");
	printf("=== 4) Reverse Insertion Sort      =====\n");
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
			rightArrow--;
		}
		array[rightArrow] = candidate;
	}
	printArray(array, numbersCount);

}

void SimpleInsertionSort(int* array, int numbersCount) {

	int candidate;
	int rightArrow, leftArrow;
	for (rightArrow = 1; rightArrow < numbersCount; rightArrow++)
	{
		printArray(array, numbersCount);
		candidate = array[rightArrow];
		leftArrow = rightArrow - 1;
		while (leftArrow >= 0 && array[leftArrow] > candidate)
		{
    	array[leftArrow + 1] = array[leftArrow];
    	leftArrow--;
		}
		array[leftArrow + 1] = candidate;
	}
	printArray(array, numbersCount);
}

void DecreaseInsertionSort(int* array, int numbersCount) {

	int candidate;
	int rightArrow, leftArrow;
	for (rightArrow = 1; rightArrow < numbersCount; rightArrow++)
	{
		printArray(array, numbersCount);
		candidate = array[rightArrow];
		leftArrow = rightArrow - 1;
		while (leftArrow >= 0 && array[leftArrow] < candidate)
		{
    	array[leftArrow + 1] = array[leftArrow];
    	leftArrow--;
		}
		array[leftArrow + 1] = candidate;
	}
	printArray(array, numbersCount);
}

void BackwardsInsertionSort(int* array, int numbersCount) {

	int candidate;
	int rightArrow, leftArrow;
	for (leftArrow = numbersCount - 2; leftArrow >= 0; leftArrow--)
	{
		printArray(array, numbersCount);
		candidate = array[leftArrow];
		rightArrow = leftArrow + 1;
		while (rightArrow < numbersCount && array[rightArrow] < candidate)
		{
    	array[rightArrow - 1] = array[rightArrow];
    	rightArrow++;
		}
		array[rightArrow - 1] = candidate;
	}
	printArray(array, numbersCount);
}


int main(int argc, char* argv[]){
	int numbersCount;
	int* array;
	int inputNumber;
	int user_input;

	showMenu();
	printf("\nInput: ");
	scanf("%d", &user_input);

	numbersCount = argc - 1; // Removes the name of the program argument
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}
	switch (user_input)
	{
	case 1:
		insertionSort(array, numbersCount);
		break;
	case 2:
		SimpleInsertionSort(array, numbersCount);
		break;
	case 3:
		DecreaseInsertionSort(array, numbersCount);
		break;
	case 4:
		BackwardsInsertionSort(array,numbersCount);
		break;
	default:
		SimpleInsertionSort(array, numbersCount);
		break;
	}
	return 0;
}
