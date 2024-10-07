#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

using namespace std;

class queue {
    int array[SIZE], front, rear;

public:
    queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int a) {
        // Check if the queue is full
        if (rear == SIZE - 1) {
            cout << "Queue is full, cannot insert " << a << endl;
            return;
        }

        // If this is the first element being inserted
        if (front == -1) {
            front+=1; // Initialize front
            rear += 1;
            array[rear] = a;
        }

        // Insert the element and increment rear
        
    }

    void display() {
        if (front == -1) {
            cout << "[]"; // Queue is empty
            return;
        }

        cout << '[';
        for (int i = front; i <= rear; i++) 
        {
            cout << array[i];
            if (i < rear) 
            {
                cout << ',';
            }
        }
        cout << ']';
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return 0; // or some other error value
        }

        int num = array[front];

        // Move front forward
        front += 1;

        // Reset the queue if it becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }

        return num;
    }
};

int main() {
    queue q1;
    int x1;

    while (1) {
        int choice;
        printf("\n1.Enqueue\n");
        printf("2.Display \n");
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
                q1.display();
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
