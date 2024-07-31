//menu driven code for implementing bubble sort,selection sort,count sort(stable)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void PrintArray(int *arr,int arrsize);
void BubbleSort(int *arr,int arrsize);
void SelectionSort(int *arr,int arrsize);
void CountSort(int *arr,int arrsize);


int main()
{
    int *arr,arrsize,choice,flag=1;
    
    while(flag==1)
    {
        cout<<"1.BUBBLE SORT,2.SELECTION SORT,3.COUNT SORT(STABLE),4.EXIT"<<endl;
        cout<<"enter the choice:";
        cin>>choice;       
        if(choice==4)
        {
            flag=0;
            break;
        }
        else
        {
        	cout<<"enter the array size:";
	        cin>>arrsize;
	        arr=(int*)malloc(arrsize*sizeof(int));
	        for(int i=0;i<arrsize;i++)
	        {
	            cout<<"enter the "<<i<<" th "<<"element:";
	            cin>>arr[i];
	        }
            if(choice==1)
            {
                BubbleSort(arr,arrsize);
            }
            else if(choice==2)
            {
                SelectionSort(arr,arrsize);
            }
            else if(choice==3)
            {
                CountSort(arr,arrsize);
        	}
        }
        PrintArray(arr,arrsize);
        free(arr);
        
    }
}

void PrintArray(int *arr,int arrsize)

	{
		cout<<"array after sorting:"<<endl;
		cout<<'[';
		for (int i=0;i<arrsize;i++)
		{
		    if(i!=arrsize-1)
		    {
		        cout<<arr[i]<<',';
		    }
		    
		    else
		    {
		        cout<<arr[i];
		        break;
		    }
		    
		}
		cout<<']'<<endl;
	}

void BubbleSort(int *arr,int arrsize)
{
    for(int i=0;i<arrsize;i++)
    {
        for(int j=i+1;j<arrsize;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void SelectionSort(int *arr,int arrsize)
{
	/*Find the Minimum Element: In each pass through the array, find the smallest element in the unsorted portion.
	Swap with the First Unsorted Element: Swap this smallest element with the first element of the unsorted portion.
	Move the Boundary: Move the boundary between the sorted and unsorted portions one element to the right.
	Repeat: Repeat the process for the remaining unsorted portion until the entire array is sorted.*/

	int min,i,j,temp;
	for(i=0;i<arrsize-1;i++)
		{
			min=i;
			for(j=i+1;j<arrsize;j++)
			{
				if(arr[min]>arr[j])
				{
					min=j;
				}
				
			}
		if(i!=min)
			{
				temp=arr[min];
				arr[min]=arr[i];
				arr[i]=temp;
			}	
		}
}

void CountSort(int *arr,int arrsize)
{
	//1)find the max element
	
	int maxi=arr[0];
	int *output=(int*)malloc(arrsize*sizeof(int));

	for(int i=0;i<arrsize;i++)
	{
		if(arr[i]>maxi)
		{
			maxi=arr[i];
		}
	}
	
	//2)initialise count array and make all to zeroes
	
	int freq[maxi+1];

	for(int i=0;i<maxi+1;i++)
	{
		freq[i]=0;
	}
	
	//3)fill the array with number of occurences
	
	for(int i=0;i<arrsize;i++)
	{
		freq[arr[i]]++;
	}
	
	//4)sum up index array values with predecessor values ie cumulative values

	for(int i=1;i<=arrsize;i++)
	{
		freq[i]+=freq[i-1];
	}
		
	//5)Build the Output Array: Iterate through the input array from right to left, place each element in its correct position in the output array, and decrement its count in the count array(stable).
	
	for (int i = arrsize - 1; i >= 0; i--)
	{
	output[freq[arr[i]] - 1] = arr[i];
	freq[arr[i]]--;
	}
    
  

  	//6)Copy the sorted elements into original array
  	for (int i = 0; i < arrsize; i++) 
	{
		arr[i] = output[i];
	}

}	