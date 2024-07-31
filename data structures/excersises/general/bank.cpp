#include<stdio.h>
#include<stdlib.h>

struct account_master
	{
		char acct_no[5];
		char name[20];
		int gender;
		char branch[20];
		char city[20];
	};

int main()
	{
		int option,flag=0;
		struct account_master am;
		printf("1 is for account creation\n.");
		printf("2 is for withdrawing amount\n.");
		printf("3 is to deposit amount.\n");
		printf("if any other option is given,it is invalid.\n");
		printf("enter the option:");
		scanf("%i",&option);
		if(option==1)	
		{	
			FILE *fptr=fopen("new_account1.txt","w");
			printf("start account creation process:");
			//while(int flag!=1)
			//	{
				if(fptr!=NULL)
					{
							
						printf("Enter account holder name:");
						scanf("%s",am.name);
						
						printf("Enter your gender(0 for female and 1 for male):");
						scanf("%i",&am.gender);
						
						printf("which branch?:");
						scanf("%s",am.branch);
						
						printf("which city do you live?:");
						scanf("%s",am.city);
						int data=fprintf(fptr,"account number:%d",am.acct_no);
						//int data=fprintf(fptr,"account number:%d\t,name:%s\t\n,gender:%d\t\n,branch:%s,city:%s\n",12344563,am.name,am.gender,am.branch,am.city);
						printf("%d",data);
					}
				else
					{
						printf("file not found.");
						return 0;
						}	
			
					
					//}
				fclose(fptr);
				return 0;
		}
			
	
	}
				
				
		/*else if(option==2)
		{
			printf("how much to withdraw sir/madam?:");
		}
		else if(option==3)	
		{
			printf("how much to deposit sir/madam?:");
		}
		else
		{
			printf("invalid");
		}*/
		
	