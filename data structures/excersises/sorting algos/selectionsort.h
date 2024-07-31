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