#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "sort.h"

void binsearch(int arr1[],int x,int size);

int main()
	{
		int flag=1,choice,arrsize,element,*arr;
		char ans;
		while(flag==1)
		{
			printf("1:sort,2:binary search,3:exit:");
			scanf("%d",&choice);
			if(choice==3)
			{
				flag=0;
				break;
			}
			else
				{
					{
					    printf("Enter the number of elements in the array: ");
					    scanf("%d", &arrsize);   
					    arr = (int*)malloc(arrsize * sizeof(int));
					    if (arr == NULL) 
							{
						        printf("Memory allocation failed.");
						        return 1;
						    }
					
					    printf("Enter %d elements one by one:\n", arrsize);
					    for (int i = 0; i < arrsize; ++i)
						{
					        printf("Enter element %d: ", i);
					        scanf("%d", &arr[i]);
				    	}	
					}
					if(choice==1)
						{
							printf("ascending or descending(a or d):");
							scanf(" %c",&ans);
							sort(arr,arrsize,ans);
							printf("Sorted array:\n");
							for (int i = 0; i < arrsize; ++i) 
							{
        						printf("element %d: %d\n", i, arr[i]);
    						}
						}
					else if(choice==2)
						{
							printf("enter the element to search:");
							scanf(" %d",&element);
							sort(arr,arrsize,'a');
							binsearch(arr,element,arrsize);
						}	
					printf("continue?y:n ");
					scanf(" %c",&ans);
					if(ans=='n')
					{
						free(arr);
						break;	
					}
					free(arr);
				}
		}
		return 0;	
	}
	
void binsearch(int arr[], int x, int size)
{
    int start = 0, end = size - 1;
    int found = 0;
    while (start <= end)
    {
        int mid = round((start + end) / 2);
        if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            printf("Element found at index %d\n", mid);
            break;
        }
    }
    
    printf("Element not found in the array\n");
    
}

	