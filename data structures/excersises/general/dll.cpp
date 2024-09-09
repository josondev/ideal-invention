//doubly linked list implementation

#include <stdio.h>
#include <stdlib.h>

class List
{
    private:
        typedef struct Node
        {
            struct Node *prev;
            int data;
            struct Node* next;
        }Node;

        Node *head,*tail;

        Node *CreateNode()
        {
            return new Node;
        }

    public:
        List()
        {
            head=nullptr;
            tail=nullptr;
        }   
        void Display()
        {
            if(head==nullptr)
            {
                printf("HEAD->NULL\n");
                printf("TAIL->NULL\n");
                return;
            }

            Node *temp=head;

            //display from the front

            printf("\nHEAD->");
            while(temp!=nullptr)
            {
                printf("|%p|%d|%p|->",temp->prev,temp->data,temp->next);
                temp=temp->next;
            }
            printf("NULL\n");

            //display from the reverse
            temp=tail;
            printf("\nTAIL->");
            while(temp!=nullptr)
            {
                printf("|%p|%d|%p|->",temp->next,temp->data,temp->prev);
                temp=temp->prev;
            }
            printf("NULL\n");
            
        }
        //insert in the beginning
        void InsertBegin(int num)
        {
            Node *newnode=CreateNode();
            newnode->data=num;
            newnode->prev = nullptr;
            newnode->next = nullptr;
            if(head==nullptr)
            {
                head=newnode;
                tail=newnode;
                printf("\nsuccessfully inserted %d freshly in the list.\n",num);
            }
            else
            {
                newnode->next=head;
                head->prev=newnode;//for coming back
                head=newnode;
                printf("\nsuccessfully inserted %d in the beginning.\n",num);
            }
        }
        //insert in the end
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
                newnode->prev=tail;
                newnode->next = nullptr;
                tail->next=newnode;
                tail=newnode;
                printf("\nSuccessfully inserted %d in the end of the list.\n",num);
                return;
            }

        }
        //insert a given number at any given position
        void InsertPosition(int num, int position) 
        {
            if (position == 0) 
            {
                InsertBegin(num);
                return;
            }

            Node *temp = head;
            Node *newnode = CreateNode();
            newnode->data = num;

            for (int i = 0; i < position - 1; i++) 
            {
                if (temp->next == nullptr) 
                {
                    printf("\ninvalid index.\n");
                    return;
                }
                temp = temp->next;
            }
            // we do a check of null pointer 
            if (temp->next != nullptr) 
            {
                newnode->next = temp->next;
                temp->next->prev = newnode;
                newnode->prev = temp;
                temp->next = newnode;
                printf("\n%d inserted successfully at position %d.\n", num, position);
                return;
            }
            //edge case checking the same nullptr which the tail points
            if (newnode->next == nullptr) 
            {
                tail = newnode;
                printf("\n%d inserted successfully at the end.\n", num);
                return;
            }
        }

        //deleting the node at beginning
        int DeleteBegin()
        {
            if(head==nullptr)
            {
                printf("\nEMPTY LIST.NOTHING TO DELETE.\n");
                return 0;
            }

            //handling list with only one node
            
            else if(head->next==nullptr)
            {
                int num=head->data;
                delete head;
                head=tail=nullptr;
                printf("\nsuccessfully deleted %d from the beginning and the list is empty.\n",num);
                return num;
            }

            //general case
            else
            {
                int num=head->data;
                head=head->next;
                delete head;
                head->prev=nullptr;
                printf("\nsuccessfully deleted %d from the beginning.\n",num);
                return(num);
            }
            return 0;
        }

        //deleteing from the end

        int DeleteEnd()
        {
            //empty list
            if(head==nullptr && tail==nullptr)
            {
                printf("\nEMPTY LIST.NOTHING TO DELETE.\n");
                return 0;
            }
            //list with one node 
            else if(tail->prev==nullptr)
            {
                int num=tail->data;
                delete tail;
                head=tail=nullptr;
                printf("\nsuccessfully deleted %d from the end and the list is empty.\n",num);
                return num;
            }
            //general case 
            else
            {
                int num=tail->data;
                tail=tail->prev;
                delete tail;
                tail->next=nullptr;
                printf("\nsucessfully deleted %d from the end of the list.\n",num);
                return num;
            }
            return 1;
        }

        int DeletePosition(int position)
        {
            if(head==nullptr)
            {
                printf("\nEMPTY LIST.NOTHING TO DELETE.\n");
                return 1;
            }
            else if(head->next==nullptr || position==0)
            {
                DeleteBegin();
                return 1;
            }
            else
            {
                Node *temp=head;
                for(int i=0;i<position-1;i++)
                {
                    if(temp->next->next==nullptr)
                    {
                        printf("the given index %d is invalid.",position);
                        return 0;
                    }
                    temp=temp->next;
                }
                if(temp->next==tail)
                {
                    int val=temp->next->data;
                    Node *tmp=tail;
                    tail=tmp->prev;
                    temp->next=nullptr;
                    delete tmp;
                    printf("\ndeleted %d successfully from the end of the list.\n",val);
                    return(val);
                }
                int val=temp->next->data;
                Node *tmp=temp->next;
                temp->next=temp->next->next;
                tmp->next->prev=temp->next;
                delete tmp;
                printf("\n%d deleted successfully from the given position %d.\n",val,position);
                return val;
            }
            return 1;
        }
        
        void Search(int num)
        {
            if(head==nullptr)
            {
                printf("\nEMPTY LIST.NOTHING TO SEARCH.\n");
                return;
            }
            Node *temp=head;int p=0;
            while(temp!=nullptr)
            {
                if(temp->data==num)
                {
                    printf("\n%d found at position %d.\n",num,p);
                    return;
                }
                p++;
            }
            printf("%d not found in the list.",num);
            return;
        }
};

int main()
{
    int choice,num,position;
    List l1;
    while(true)
    {
        printf("\n1)insert in beginning\n2)insert in the end\n3)insert in position\n4)delete in beginning\n5)delete in end\n6)delete in position\n7)search for an element\n8)display\n9)exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nenter the number to be inserted in the beginning:");
                scanf("%d",&num);
                l1.InsertBegin(num);
                break;

            case 2:
                printf("\nenter the number to be inserted in the end:");
                scanf("%d",&num);
                l1.InsertEnd(num);
                break;    

            case 3:
                printf("\nenter the number to be inserted:");
                scanf("%d",&num);
                printf("\nenter the position to insert %d in the list:",num);
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
                printf("\nenter the position to delete element:");
                scanf("%d",&position);
                l1.DeletePosition(position);
                break;

            case 7:
                printf("\nenter the element to search in the list:");
                scanf("%d",&num);
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
