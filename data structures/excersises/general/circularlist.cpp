#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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
                printf("\ninserted %d freshly in the list.\n",num);
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
        
            printf("\nsuccessfully inserted %d in the beginning.\n",num);
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
                printf("\ninserted %d successfully at end.\n",num);
                return;
            }
        }

        void InsertPosition(int num,int position)
        {
            if(position==0) 
            {
                InsertBegin(num);
                return;
            }
            Node *newnode=CreateNode();
            newnode->data=num;
            Node *temp=head;
            // to track the given position.If head occurs before the given index then the index does not exist
            for(int i=0;i<position-1;i++)
            {
                if(temp->next==head)
                {
                    printf("\ngiven index does not exist.\n");
                    return;
                }
                temp=temp->next;
            }
            //once when we reach the before position we start inserting the node
            newnode->next=temp->next;
            temp->next=newnode;
            printf("\n%d inserted successfully at position %d.\n",num,position);
            return;
        }
 
        int DeleteBegin()
        {
            if(head==nullptr)
            {
                printf("\nList is empty. Nothing to delete.\n");
                return 1;
            }
            //single node case
            else if(head->next==head)
            {
                int num=head->data;
                delete(head->next);
                head=nullptr;
                printf("\ndeleted %d from beginning and now list is a fresh one.\n",num);
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
                printf("\nsuccessfully deleted %d from beginning.\n",num);
                return num;
            }
        }
        
        int DeleteEnd()
        {
            if(head==nullptr)
            {
                printf("\nEmpty list.nothing to delete.\n");
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
                printf("\ndeleted %d successfully from the end.",num);
                return num;
            }

        }

        int DeletePosition(int position)
        {
            if(head==nullptr)
            {
                printf("\nEmpty list.nothing to delete.\n");
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
                printf("\nsuccessfully deleted %d in position %d.",num,position);
                return num;
            }
        }

        void Search(int num)
        {
            if(head==nullptr)                  //empty list
            {
                printf("\nlist is empty.\n");
                return;
            }
            else if(head->next==head)
            {
                if(head->data==num)         //list with one element
                {
                    printf("\n%d found at the beginning.\n",num);
                    return;
                }
                else
                {
                    printf("\n%d not found in the list.\n",num);
                    return;
                }
            }
            Node *temp=head;
            int p=0;
            while(temp->next!=head)
            {
                if(temp->data==num)
                {
                    printf("\n%d found in index %d.\n",num,p);
                    return;
                }                
                temp=temp->next;
                p++;
            }
            printf("\n%d not found in the list.\n",num);
            return;
        }
        
        void Display()
        {
            if(head == nullptr)
            {
                printf("EMPTY LIST\n");
                printf("head->null\n");
                return;
            }

            Node *temp=head;
            printf("HEAD->");
            while(true)
            {
                printf("|%d|%p|->",temp->data,temp->next);
                temp = temp->next;
                if(temp==head) break;
            }
            printf("HEAD\n"); 
        }
   
};

int main()
{
    int choice,num,position;
    List l1;
    while(true)
    {
        printf("\n1)insert in beginning\n2)insert in the end\n3)insert in position\n4)delete in begin\n5)delete in end\n6)delete in position\n7)search for an element\n8)display\n9)exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        if(choice==9) 
            break;
        else
        {
            switch(choice)
            {
                case 1:
                    printf("enter the number to insert at begin:");
                    scanf("%d",&num);
                    l1.InsertBegin(num);
                    break;

                case 2:
                    printf("enter the number to insert at end:");
                    scanf("%d",&num);
                    l1.InsertEnd(num);
                    break;

                case 3:
                    printf("enter the number to insert:");
                    scanf("%d",&num);
                    printf("enter the position to insert:");
                    scanf("%d",&position);
                    l1.InsertPosition(num,position);
                    break;

                case 4:
                    l1.DeleteBegin();
                    break;

                case 5:
                    l1.DeleteEnd();
                    break;

                case 6:
                    printf("enter a position to delete:");
                    scanf("%d",&position);
                    l1.DeletePosition(position);
                    break;

                case 7:
                    printf("enter the number to search in the list:");
                    scanf("%d",&num);
                    l1.Search(num);
                    break;

                case 8:
                    l1.Display();
                    break; 

            }
        }
        
    }
    
}