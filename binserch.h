void sort(int arr1[], int size) { 
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