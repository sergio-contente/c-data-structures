#include <stdio.h>
#include <stdlib.h>
#include "../Resources.c"

typedef int bool;
#define TRUE  1
#define FALSE 0

void printMenu(){
	printf("========================================\n");
	printf("============  Binary Search    =========\n");
	printf("========================================\n");
	printf("****************************************\n");
	printf("========================================\n");
	printf("============   Made by:            =====\n");
	printf("===   Sergio Contente              =====\n");
	printf("========================================\n");
	printf("=== 1) Recursive Binary Search     =====\n");
	printf("=== 2) Iteractive Binary Search    =====\n");
	printf("========================================\n");

}

void RecursiveBinarySearch(int* array, int value, int left, int right, bool foundValue){
	int mid;
	if(foundValue == FALSE){

		// Base case
		if (right == left)
		{
			if (array[left] == value)
			{
				printf("Value %d found! It's the %d element of the ordered array.", value, left + 1);
				foundValue = TRUE;
				return;
			} else {
				printf("O valor %d is not inside of the elements array.", value);
				return;
			} 
		} else {
				mid = (left + right)/2;
				if (array[mid] == value) {
					printf("Value %d found! It's the %d element of the ordered array.", value, mid + 1);
					foundValue = TRUE;
					return;
				} 
				else if (value < array[mid])
				{
					RecursiveBinarySearch(array, value, left, mid - 1, foundValue);
				} else {
					RecursiveBinarySearch(array, value, mid + 1, right, foundValue);
				}
			}
	}
}

void IterativeBinarySearch(int* array, int numbersCount, int value) {
	int left = 0;
	int right = numbersCount - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right)/2;
		if (array[mid] == value)
		{
			printf("Value %d found! It's the %d element of the ordered array.", value, mid + 1);
			return;
		} else {
				if (value < array[mid])
				{
					right = mid - 1;
				} else {
					left = mid + 1;
				}
		}
	}

	printf("O valor %d is not inside of the elements array.", value);
}	
	


int main(int argc, char* argv[]){
	int user_input, selection_input, numbersCount, inputNumber;
	int* array;
	printMenu();
	printf("\nInput: ");
	scanf("%d", &selection_input);
	printf("========================================\n");
	printf("Value: ");
	scanf("%d", &user_input);
	printf("========================================\n");

	numbersCount = argc - 1; // Removes the name of the program argument
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}
	mergeSort(array, 0, numbersCount - 1);
	switch (selection_input)
	{
	case 1:
		RecursiveBinarySearch(array, user_input, 0, numbersCount - 1, FALSE);
		break;
	case 2:
		IterativeBinarySearch(array, numbersCount, user_input);
		break;
	default:
		RecursiveBinarySearch(array, user_input, 0, numbersCount - 1, FALSE);
		break;
	}
	return 0;
}
