#include <stdio.h>
#include <stdlib.h>
#include <math.h> //for pi
#include <stdbool.h> 

void circlearea(double *radius);
void rectanglearea(double *length,double *breadth);
void squarearea(double *side);

int main()
{
    //dynamically allocating memories

    int *choice=(int*)malloc(sizeof(int));
    double *radii=(double*)malloc(5*sizeof(double));
    double *length=(double*)malloc(5*sizeof(double));
    double *breadth=(double*)malloc(5*sizeof(double));
    double *side=(double*)malloc(5*sizeof(double));

    while(true)
    {
        printf("enter the choice(1:rectangle,2:circle,3:square,4:exit):");
        scanf(" %d",choice);
        if(*choice==4)
        {
            break;
        }
        else
        {
            if(*choice==2)
            {
                printf("enter the radius:");
                scanf(" %lf",radii);
                circlearea(radii);
                printf("\n");
            }
            else
            {
                if(*choice==3)
                    {
                        printf("enter the side:");
                        scanf(" %lf",side);
                        squarearea(side);

                    }
                else if(*choice==1)
                    {
                        printf("enter the length:");
                        scanf(" %lf",length);
                        printf("enter the breadth:");
                        scanf(" %lf",breadth);
                        rectanglearea(length,breadth);
                    }
            }
            

        }
    }
    free(choice);
    free(radii);
    free(breadth);
    free(length);
    return 0;
}
void circlearea(double *radii)
{
    printf("area is:%f",M_PI*(*radii)*(*radii));
}
void rectanglearea(double *length,double *breadth)
{
    printf("area is:%f",(*length)*(*breadth));
}
void squarearea(double *side)
{
    printf("area is:%f",(*side)*(*side));
}
