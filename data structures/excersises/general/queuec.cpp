#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

using namespace std;

class queue
{
    int array[SIZE],front,rear;
    public:
        queue()
        {
            front=-1;
            rear=-1;
        }
    void enqueue(int element)
    {
        //full condition
        if((front==0 && rear==SIZE-1 ) || (rear+1%SIZE)==front)
        {
            cout<<'\n queue is full.';
            return;
        }

        else if (front == -1) 
        {
            front+=1; // Initialize front
            rear += 1;
            array[rear] = element;
        }
        else
        {
            rear=(rear+1)%SIZE;//resetting the rear to point to the 1st element so that we can insert the element
            array[rear]=element;
        }
    }   
    int peek() 
    {
        if (front == -1) 
        {
            cout << "Queue is empty." << endl;
            return 0; // or some other error value
        }
        return array[front]; // Return the front element
    }
    int dequeue()
    {
        if (front == -1) 
        {
            cout << "Queue is empty." << endl;
            return 0; // or some other error value
        }
        int num=array[front];
        // Move front forward
        if (front == rear) 
        {
            // Queue is now empty
            front = -1;
            rear = -1;
        } 
        else 
        {
            front = (front + 1) % SIZE;
            return num;
        }
    }
};

int main() {
    queue q1;
    int x1;

    while (1) {
        int choice;
        printf("\n1.Enqueue\n");
        printf("2.Peek \n");
        printf("3.Dequeue \n");
        printf("4.Exit\n");
        cout << "Enter your choice: ";
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &x1);
                q1.enqueue(x1);
                break;

            case 2:
                q1.peek();
                break;

            case 3:
                x1 = q1.dequeue();
                if (x1 != 0) { // Only print if it's a valid dequeue
                    printf("Dequeued: %d\n", x1);
                }
                break;

            case 4:
                printf("YOU HAVE EXITED THE PROGRAM\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}