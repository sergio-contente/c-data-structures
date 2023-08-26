
#include<stdio.h>
void merge(int* array, int left, int middle, int right){
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
		int middle = (left+right)/2;

		mergeSort(array, left, middle);
		mergeSort(array, middle+1, right);
		merge(array, left, middle, right);
	}
}
