#include <stdio.h>
#include <stdlib.h> // For malloc and free

int find(int num, int arr1[], int size);

int main() {
    int arrsize, num1, i;
    
    printf("Enter the number you want to find: ");
    scanf("%d", &num1);
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &arrsize);
    
    int *arr = (int *)malloc(arrsize * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter %d elements one by one:\n", arrsize);
    for (i = 0; i < arrsize; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    if (find(num1, arr, arrsize) == 1) {
        printf("%d found.\n", num1);
    } else {
        printf("%d not found.\n", num1);
    }
    
    free(arr); // Free dynamically allocated memory
    return 0;
}

int find(int num, int arr1[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] == num) {
            return 1;
        }
    }
    return 0;
}
    
