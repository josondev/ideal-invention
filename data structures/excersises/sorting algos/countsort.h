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