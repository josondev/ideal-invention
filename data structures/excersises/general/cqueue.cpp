#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class circular_queue
{
    private:
        typedef struct Node
        {
            int data;
            Node *next;
        }Node;

        Node *front, *rear;

        Node *CreateNode()
        {
            return new Node;
        }
    public:
        circular_queue()
        {
            front = nullptr;
            rear = nullptr;
        }
        void Enqueue(int element)
        {
            Node *newnode = CreateNode();
            newnode->data = element;
            if (front == nullptr)
            {
                newnode->next = newnode;
                front = newnode;
                rear = newnode;
                cout << "\nsuccessfully enqueued " << element << " freshly in the circular queue.\n";
                return;
            }
            newnode->next = front;
            rear->next = newnode;
            rear = newnode;
            cout << "\nsuccessfully enqueued " << element << " in the circular queue.\n";
        }
        int Peek()
        {
            if (front == nullptr)
            {
                cout << "\nthe circular queue is empty.\n";
                return 0;
            }
            return front->data;
        }
        int Dequeue()
        {
            if (front == nullptr)
            {
                cout << "\ncircular queue is empty. Nothing to Dequeue.\n";
                return 0;
            }
            int num = front->data;
            if (front == rear) // Only one element
            {
                delete front;
                front = nullptr;
                rear = nullptr;
                return num; // Return immediately after deleting the only element
            }
            Node *temp = front;
            rear->next = temp->next;
            front = temp->next;
            delete temp;
            return num;
        }

        void Display()
        {
            if (front == nullptr)
            {
                cout << "\nFRONT->NULL" << endl;
                return;
            }
            Node *temp = front;
            cout << "\nFRONT->";
            while (true)
            {
                cout << '|' << temp->data << '|' << temp->next << '|' << "->";
                temp = temp->next;
                if (temp == front) break;
            }
            cout << "FRONT\n";
        }
};

int main()
{
    int num, choice;
    circular_queue cq1;
    while (true)
    {
        cout << "\n1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\n" << endl;
        cout << "enter your choice:";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "\nenter the element to enqueue:";
                cin >> num;
                cq1.Enqueue(num);
                break;

            case 2:
                num = cq1.Dequeue();
                if(num == 0)
                {
                    cout << "\nthe queue is empty.\n";
                }
                else
                {
                    cout << "\nthe element dequeued is: " << num << endl;
                }
                break;

            case 3:
                num = cq1.Peek();
                if (num == 0)
                {
                    cout << "\nthe circular queue is empty.\n";
                }
                else
                {
                    cout << "\nthe first most element in the circular queue is: " << num << endl;
                }
                break;

            case 4:
                cq1.Display();
                break;

            case 5:
                return 0;

            default:
                cout << "enter the correct choice:";
        }
    }
}
