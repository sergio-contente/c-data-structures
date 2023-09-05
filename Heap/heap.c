#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Resources.c"

int GetParent(int node_index){
	return (node_index - 1) /2;
}

int GetLeftChild(int node_index){
	return 2 * node_index + 1;
}

int GetRightChild(int node_index){
	return 2 * node_index + 2;
}

void MaxHeapify(int* A, int node_index, int heap_size){
	int left, right, greatest;
	left = GetLeftChild(node_index);
	right = GetRightChild(node_index);

		printf("left: %d\n", left);
		printf("right: %d\n", right);


	if (left < heap_size && A[left] > A[node_index])
	{
		greatest = left;
	}
	else {
		greatest = node_index;
	}

	if (right < heap_size && A[right] > A[greatest])
	{
		greatest = right;
	}

		printf("greatest: %d\n", greatest);

	if (greatest != node_index)
	{
		swap(&A[node_index], &A[greatest]);
		MaxHeapify(A, greatest, heap_size);
	}
}

void BuildMaxHeap(int* A, int size) {
	printf("size: %d\n", size);
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		printf("Entrou no for do build\n");
		MaxHeapify(A, i, size);
		printArray(A, size);
	}
}

void HeapSort(int* A, int size) {
	int original_size = size;
	BuildMaxHeap(A, size);
	while (size > 0)
	{
		swap(&A[0], &A[size - 1]);
		size--;
		BuildMaxHeap(A, size);
	}
	printArray(A, original_size);
}

int main(int argc, char* argv[]){
	int numbersCount;
	int* array;
	int inputNumber;
	int user_input;
	int counter;


	clock_t t_0;
	double time_consumed;

	// printf("\nInput: ");
	// scanf("%d", &user_input);
	// printf("========================================\n");


	numbersCount = argc - 1; // Removes the name of the program argument
	array = (int*)malloc(sizeof(int*)*numbersCount);
	for(int i = 0; i < numbersCount; i++) {
		inputNumber = atoi(argv[i + 1]); // argv[0] is the name of the program
		array[i] = inputNumber;
	}
	// Apparently, we can't use sizeof() with pointers, only with static arrays
	// printf("Size of array_name: %d\n", sizeof(array));
	// printf("Size of array_index: %d\n", sizeof(array[0]));
	// printf("Size na main: %d\n", size);
	HeapSort(array, numbersCount);
	return 0;
}
