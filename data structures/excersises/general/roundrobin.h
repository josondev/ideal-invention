#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

extern int time_alloted;

class List
{
    private:
        typedef struct Node
        {
            int data;
            struct Node* next;
        }Node;

        Node *CreateNode()
        {
            return new Node;
        }

        //destructor fn in private
        void DeleteNode(Node* ptr) 
        {
            if(ptr == nullptr) 
            {
                return;
            }
            DeleteNode(ptr->next);
            delete ptr;
        }

    public:
         //constructor
        Node *head; 
        List()
        {
            head=nullptr;
        }   

        //destructor
        ~List()
        {
            DeleteNode(head);
        } 

        void InsertBegin(int num)
        {
            Node* newnode = CreateNode();
            newnode->data=num;
            if(head==nullptr)
            {
                // If the list is empty, make the new node point to itself
                newnode->next=newnode;
                head=newnode;
                cout<<"\ninserted "<<num<<" freshly in the Queue.\n"<<endl;
                return;
            }
            else
            {
                // Traverse to the end
                Node *temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                // Insert at the beginning
                // Update the last node's next pointer
                newnode->next=head;
                temp->next=newnode;
                head=newnode;
            }
        
            cout<<"\nsuccessfully inserted "<< num <<" in the beginning.\n";
        }

        void InsertEnd(int num)
        {
            if(head==nullptr)
            {
                InsertBegin(num);
                return;
            }
            else
            {
                Node *newnode=CreateNode();
                newnode->data=num;
                Node *temp=head;
                while(true)
                {
                    temp=temp->next;
                    if(temp==head) break;
                }
                newnode->next=head->next;
                temp->next=newnode;
                cout<<"\ninserted "<<num<<" successfully at end.\n"<<endl;
                return;
            }
        }

 
        int DeleteBegin()
        {
            if(head==nullptr)
            {
                cout<<"\nQueue is empty.Nothing to delete.\n"<<endl;
                return 0;
            }
            //single node case
            else if(head->next==head)
            {
                int num=head->data;
                delete(head->next);
                head=nullptr;
                cout<<"\ndeleted "<<num<<" from beginning and now Queue is a fresh one.\n";
                return(num);
            }
            //general case go till end to point to the beginning node
            else 
            {
                Node* temp = head;
                while (temp->next != head) 
                {
                    temp = temp->next;
                }
                int num = head->data;
                temp->next = head->next;
                delete head;
                head = temp->next;
                return num;
            }
        }       
        
        void Display()
        {
            if(head == nullptr)
            {
                cout<<"EMPTY LIST\n";
                cout<<"HEAD->NULL\n";
                return;
            }

            Node *temp=head;
            cout<<"\nHEAD->";
            while(true)
            {
                cout<<'|'<<temp->data<<'|'<<temp->next<<'|'<<"->";
                temp = temp->next;
                if(temp==head) break;
            }
            cout<<"HEAD\n"; 
        }

        void Execute()
        {
            int data = DeleteBegin()-time_alloted;

            if (data > 0)
                InsertEnd(data);
            cout<<"Executed ";
            if (head == nullptr)
            {
                cout<<"& Completed\n";
                return;
            }
        }  
   
};