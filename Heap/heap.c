#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Resources.c"

int GetParent(int node_index){
	return node_index/2;
}

int GetLeftChild(int node_index){
	return 2 * node_index;
}

int GetRightChild(int node_index){
	return 2 * node_index + 1;
}

void MaxHeapify(int* A, int node_index){
	int left, right, greatest, heap_size;
	left = GetLeftChild(node_index);
	right = GetRightChild(node_index);
	heap_size = GetArraySize(A);

	if (left <= heap_size && A[left] > A[node_index])
	{
		greatest = left;
	}
	else {
		greatest = node_index;
	}

	if (right <= heap_size && A[right] > A[node_index])
	{
		greatest = right;
	}

	if (greatest != node_index)
	{
		swap(&A[node_index], &A[greatest]);
		MaxHeapify(A, greatest);
	}
}

void BuildMaxHeap(int* A) {
	int size = GetArraySize(A);
	for (int i = size - 1; i <= 0; i--)
	{
		MaxHeapify(A, i);
	}
	printArray(A, size);
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
	BuildMaxHeap(array);
	return 0;
}
