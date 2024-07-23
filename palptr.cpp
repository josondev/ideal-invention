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
		end++;
	}
	string=(char *) realloc(string,(end-start+1)*sizeof(char));
	end--;
	while(start<=end)
	{
		if(*start!=*end)
		{
			printf("%s not a palindrome.",string);
			return 0;
		}
		end--;
		start++;
	}
	free(str);
	printf("%s is a palindrome.",string);
}

