
#include <stdio.h>
#include <stdlib.h>

void sort(int arr1[], int size, char ans);

int main() 
{
    int arrsize, i;
    char ans;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &arrsize);   
    int *arr = (int*)malloc(arrsize * sizeof(int));
    if (arr == NULL) 
		{
	        printf("Memory allocation failed.");
	        return 1;
	    }

    printf("Enter %d elements one by one:\n", arrsize);
    for (i = 0; i < arrsize; ++i) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("ascending or descending(a or d): ");
    scanf(" %c", &ans); // Add a space before %c to consume the newline character
    sort(arr, arrsize, ans);
    for (i = 0; i < arrsize; ++i) {
        printf("element %d: %d\n", i, arr[i]);
    }
    free(arr); // Free dynamically allocated memory
    return 0;
}

void sort(int arr1[], int size, char ans) {
    if (ans == 'd') 
		{
	        for (int i = 0; i < size; i++) {
	            for (int j = i + 1; j < size; j++) {
	                if (arr1[i] < arr1[j]) 
						{
		                    int temp = arr1[i];
		                    arr1[i] = arr1[j];
		                    arr1[j] = temp;
		                }
	            }
	        }
	    } 
	else if (ans == 'a') 
		{
	        for (int i = 0; i < size; i++) {
	            for (int j = i + 1; j < size; j++) {
	                if (arr1[i] > arr1[j]) 
						{
		                    int temp = arr1[i];
		                    arr1[i] = arr1[j];
		                    arr1[j] = temp;
		                }
	            }
	        }
	    }
}