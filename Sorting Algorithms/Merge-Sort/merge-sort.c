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

void merge(int* array, int left, int middle, int right){
	printf("Left: %d  Middle: %d  Right: %d\n", left, middle, right);
	int arrowLeft, arrowRight, arrowMerge = left;
	int length_left = middle - left + 1;
	int length_right = right - middle;

	int* leftArray; 
	int* rightArray;
	leftArray = (int*)malloc(sizeof(int*) * length_left);
	rightArray = (int*)malloc(sizeof(int*) * length_right);

	//Creating the two arrays that will be merged later
	for (arrowLeft = 0; arrowLeft < length_left; arrowLeft++)
	{
		leftArray[arrowLeft] = array[arrowLeft + left]; // Filling the left sorted array
	}
	
	for (arrowRight = 0; arrowRight < length_right; arrowRight++)
	{
		rightArray[arrowRight] = array[arrowRight + middle + 1]; // Filling the right sorted array
	}
	
	printf("\nArray left: ");
	printArray(leftArray, length_left);

	printf("\nArray right: ");
	printArray(rightArray, length_right);

	// Merge loop
	arrowLeft = 0;
	arrowRight = 0;
	while (arrowLeft < length_left && arrowRight < length_right)
	{
		if (leftArray[arrowLeft] <= rightArray[arrowRight])
		{
			array[arrowMerge] = leftArray[arrowLeft];
			arrowLeft++;
		} else {
			array[arrowMerge] = rightArray[arrowRight];
			arrowRight++;
		}
		arrowMerge++;
	}
	
	// If one of the arrays finished before the other,
	// put the rest of the elements on the merged array

	while (arrowLeft < length_left)
	{
		array[arrowMerge] = leftArray[arrowLeft];
		arrowLeft++;
		arrowMerge++;
	}
	
	while (arrowRight < length_right)
	{
		array[arrowMerge] = rightArray[arrowRight];
		arrowRight++;
		arrowMerge++;
	}
	
	//clean memory spaces of the auxiliary arrays
	free(leftArray);
	free(rightArray);

}

void mergeSort(int* array, int left, int right) {
	if (left < right)
	{
		printArray(array, left + right - 1);	
		int middle = (left+right)/2;

		mergeSort(array, left, middle);
		mergeSort(array, middle+1, right);
		merge(array, left, middle, right);
		printArray(array, right - left + 1);
	}
}

int main(int argc, char* argv[]) {
	int* array;
	int numbersCount = argc - 1; // Removes the name of the program argument;
	int inputNumber;
 	showMenu();

	numbersCount = argc - 1; // Removes the name of the program argument
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}
	mergeSort(array, 0, numbersCount - 1);
	return 0;
}
