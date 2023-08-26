#include <stdio.h>
#include <stdlib.h>

void showMenu() {
	printf("========================================\n");
	printf("============  INSERTION SORT   =========\n");
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
}

void printArray(int* array, int numbersCount){
	printf("Array:\n[ ");
	
	for (int i = 0; i < numbersCount; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("]\n");
}

void RecursiveInsertionSort(int* array, int numbersCount, int counter) {
	if (numbersCount < 0)
	{
		return;
	}
	numbersCount--;
	counter++;
	RecursiveInsertionSort(array, numbersCount, counter);
	int candidate = array[numbersCount];
	printf("Recursion step number %d\nCandidate: %d\n", numbersCount, candidate);
	printArray(array, numbersCount);
	int leftArrow = numbersCount - 2;
	
	while (leftArrow >= 0 && array[leftArrow] > candidate)
	{
		array[leftArrow + 1] = array[leftArrow];
		leftArrow--;
		printArray(array, numbersCount);
	}
	array[leftArrow + 1] = candidate;
	printArray(array, numbersCount);
}

void InsertionSort(int* array, int numbersCount) {

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
	int counter;

	showMenu();
	printf("\nInput: ");
	scanf("%d", &user_input);
	printf("========================================\n");


	numbersCount = argc - 1; // Removes the name of the program argument
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}
	switch (user_input)
	{
	case 1:
		counter = 0;
		RecursiveInsertionSort(array, numbersCount, counter);
		break;
	case 2:
		InsertionSort(array, numbersCount);
		break;
	case 3:
		DecreaseInsertionSort(array, numbersCount);
		break;
	case 4:
		BackwardsInsertionSort(array,numbersCount);
		break;
	default:
		InsertionSort(array, numbersCount);
		break;
	}
	return 0;
}
