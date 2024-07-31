#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *string=(char*)malloc(10*sizeof(char));
	printf("enter the word:");
	scanf("%s",string);
	char *start=string,*end=string;
	while(*(end)!='\0')
	{
		end++;						// point end towards string end
	}
	string=(char *) realloc(string,(end-start+1)*sizeof(char));		//calculate actual size and then reassign it
	end--;															//The end-- statement is used to move the end pointer to the character just before the null character '\0' at the end of the string
	while(start<=end)
	{
		if(*start!=*end)											//check for dereferenced values of start end
		{
			printf("%s not a palindrome.",string);
			return 0;
		}
		end--;
		start++;
	}
	free(string);
	printf("%s is a palindrome.",string);
}

