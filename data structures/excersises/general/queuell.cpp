#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class queue
{
    private:
        typedef struct Node 
        {
            int data;
            Node *next;
        }Node;

        Node *front,*rear;

        Node* CreateNode()
        {
            return new Node;
        }
    public:
        queue()
        {
            front=nullptr;
            rear=nullptr;
        }
        void Enqueue(int element)       //insert at end in linked list
        {
            Node *newnode=CreateNode();
            newnode->data=element;
            if(front==nullptr)
            {
                newnode->next=front;
                front=newnode;
                rear=newnode;
                cout<<"\nenqueued "<<element<<" freshly into the queue.\n";
                return;
            }
            newnode->next=rear->next;
            rear->next=newnode;
            rear=newnode;
            cout<<"\nenqueued "<<element<<" into the queue.\n";
            return;
        }
        int Dequeue()                   //delete at beginning
        {
            if(front==nullptr) return 0;
            if(front==rear)
            {
                int num=front->data;
                Node *temp=front;
                front=nullptr;
                rear=nullptr;
                delete temp;
                return(num);
            }
            int num=front->data;
            Node *temp=front;
            front=temp->next;
            delete temp;
            return num;
        }
        int Peek()
        {
            if(front==nullptr)return 0;
            return(front->data);
        }
        void Display()
        {
            Node *temp=front;                //temporary pointer to traverse the queue
            cout<<"\nFRONT->";
            while(temp!=NULL)
            {
                cout<<'|'<<temp->data<<'|'<<temp->next<<'|'<<"->";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }

};

int main()
{
    int num,choice;
    queue q1;    
    while(true)
    {
        cout<<"\n1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit\n"<<endl;
        cout<<"enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nenter the element to enqueue:";
                cin>>num;
                q1.Enqueue(num);
                break;

            case 2:
                if(q1.Dequeue()==0)cout<<"\nqueue is empty.\n";break;
                cout<<"\nthe element dequeued: "<<q1.Dequeue()<<endl;  
                break;

            case 3:
                if(q1.Peek()==0)cout<<"empty queue nothing to peek.";break;
                cout<<"\nthe first most element in the queue is:"<<q1.Peek(); 
                break;

            case 4:
                q1.Display();
                break;

            case 5:
                return 0;            
        }
    }
}