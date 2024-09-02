#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class List
{
    private:
        typedef struct Node
        {
            int data;
            struct Node* next;
        }Node;

        Node *head;

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
                cout<<"\ninserted "<<num<<" freshly in the list.\n"<<endl;
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

        void InsertPosition(int num,int position)
        {
            if(position==0 || head==nullptr) 
            {
                InsertBegin(num);
                return;
            }
            Node *newnode=CreateNode();
            newnode->data=num;
            Node *temp=head;                                              //temporary pointer to traverse the list
            if((head==nullptr && position>0)|| position<0)                                  //empty list checking 
            {
                cout<<"invalid position.\n";
                return;
            }
            // to track the given position.If head occurs before the given index then the index does not exist
            for(int i=0;i<position-1;i++)
            {
                if(temp->next==head)
                {
                    cout<<"\ngiven index "<<i<<" does not exist.\n"<<endl;
                    return;
                }
                temp=temp->next;
            }
            //once when we reach the before position we start inserting the node
            newnode->next=temp->next;
            temp->next=newnode;
            cout<<num<<" inserted successfully at position "<<position<<'.'<<endl;
            return;
        }
 
        int DeleteBegin()
        {
            if(head==nullptr)
            {
                cout<<"\nList is empty.Nothing to delete.\n"<<endl;
                return 1;
            }
            //single node case
            else if(head->next==head)
            {
                int num=head->data;
                delete(head->next);
                head=nullptr;
                cout<<"\ndeleted "<<num<<" from beginning and now list is a fresh one.\n";
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
                cout<<"\nsuccessfully deleted "<<num <<" from beginning.\n"<<endl;
                return num;
            }
        }
        
        int DeleteEnd()
        {
            if(head==nullptr)
            {
                cout<<"\nEmpty list.nothing to delete.\n";
                return 1;
            }
            else if(head->next==head)
            {
                DeleteBegin();
                return 1;
            }
            else
            {
                Node *temp=head;
                while(temp->next->next!=head)
                {
                    temp=temp->next;
                }
                int num=temp->data;
                delete(temp->next);
                temp->next=head;
                cout<<"\ndeleted "<<num<<" successfully from the end.\n"<<endl;
                return num;
            }

        }

        int DeletePosition(int position)
        {
            if(head==nullptr)
            {
                cout<<"\nEmpty list.nothing to delete.\n";
                return 1;
            }
            else if(head->next==head || position==0)
            {
                DeleteBegin();
                return 1;
            }
            else
            {
                Node *temp=head;
                for(int i=0;i<position-1;i++)
                {
                    temp=temp->next;
                }
                int num=temp->next->data;
                delete(temp->next);
                temp->next=temp->next->next;
                cout<<"\nsuccessfully deleted "<<num <<" in position "<<position<<" ."<<endl;
                return num;
            }
        }

        void Search(int num)
        {
            if(head==nullptr)                  //empty list
            {
                cout<<"\nlist is empty.\n"<<endl;
                return;
            }
            else if(head->next==head)
            {
                if(head->data==num)         //list with one element
                {
                    cout<<num<<" found at the beginning.\n"<<endl;
                    return;
                }
                else
                {
                    cout<<num<<" not found in the beginning."<<endl;
                    return;
                }
            }
            Node *temp=head;
            int p=0;
            while(temp->next!=head)
            {
                if(temp->data==num)
                {
                    cout<<num<<" found in index "<<p<<endl;
                    return;
                }                
                temp=temp->next;
                p++;
            }
            cout<<num<<" not found in the list.";
            return;
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
   
};

int main()
{
    int choice,num,position;
    List l1;
    while(true)
    {
        cout<<"\n1)insert in beginning\n2)insert in the end\n3)insert in position\n4)delete in begin\n5)delete in end\n6)delete in position\n7)search for an element\n8)display\n9)exit\n";
        cout<<"enter your choice:";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"enter the number to insert at begin:";
                cin>>num;
                l1.InsertBegin(num);
                break;

            case 2:
                cout<<"enter the number to insert at end:";
                cin>>num;
                l1.InsertEnd(num);
                break;

            case 3:
                cout<<"enter the number to insert:";
                cin>>num;
                cout<<"enter the position to insert:";
                cin>>position;
                l1.InsertPosition(num,position);
                break;

            case 4:
                l1.DeleteBegin();
                break;

            case 5:
                l1.DeleteEnd();
                break;

            case 6:
                cout<<"enter a position to delete:";
                cin>>position;
                l1.DeletePosition(position);
                break;

            case 7:
                cout<<"enter the number to search in the list:";
                cin>>num;
                l1.Search(num);
                break;

            case 8:
                l1.Display();
                break; 

            case 9:
                return 0;
            }
        }
        
    }
    
