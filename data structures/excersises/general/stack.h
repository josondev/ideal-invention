#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class list
{
    typedef struct node
    {
        char data;
        node *next;
    }node;

    node *head;

    node *createnode()
    {
        return new node;
    }

    public:

        list()
        {
            head=nullptr;
        }

        void InsertBeginning(char letter)
        {    
            node *newnode=createnode();
            newnode->data=letter;
            newnode->next=head;
            head=newnode;
            /*cout<<"\n";
            cout<<"Pushed "<<letter<<" successfully in the beginning."<<endl;
            cout<<"\n";*/
            return;     
        }

        void Push(char letter)              //insert at end
        {
            if(head==nullptr)
            {
                InsertBeginning(letter);
                return;
            }

            node *temp=head;

            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }

            node *newnode=createnode();
            newnode->data=letter;
            newnode->next=temp->next;
            temp->next=newnode;
            /*cout<<"\n";
            cout<<"Pushed "<<letter<<" successfully in the Stack."<<endl;
            cout<<"\n";*/
            return;            
        }

        char DeleteBegin()
        {
            if(head==NULL)                                              //empty list checking 
            {
                //cout<<"\nempty stack,nothing to delete.\n";
                return 0;
            }
            node *temp=head;                                            //pointing the temp to head initially to n
            char a=temp->data;
            head=head->next;
            free(temp);
            //printf("\nsuccessfully deleted %c from the beginning of the list.\n",a);
            return a;
        }

        char DeleteEnd()
        {
            if(head==nullptr)
            {
                //printf("\nEmpty Stack.\n");
                return 0;
            }
            else if(head->next == nullptr) 
            {                                        // List has only one node
                DeleteBegin();
                return 1;
            }
            node *temp=head;
            while(temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
            char a=temp->next->data;
            free(temp->next);
            temp->next=nullptr;
            //printf("\nsuccessfully popped %c from the stack.\n",a);
            return a;
        }

        char Peek()
        {
            if(head==NULL)                                              //empty list checking 
                return 0;

            else if(head->next == nullptr) 
            {                                                           // List has only one node
                return(head->data);
            }

            else
            {
                node *temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                return(temp->data);
            }
        }

        void display()
        {
            node *temp=head;                //temporary pointer to traverse the list
            //printf("HEAD->");
            while(temp!=NULL)
            {
                printf("%c",temp->data);
                temp=temp->next;
            }
            //printf("NULL\n");
        }

};