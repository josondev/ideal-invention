#include <stdio.h>
#include <stdlib.h>

class Linked
{
    typedef struct Node
    {
        int data;
        struct Node *next;
    }Node;

    Node *head;

    Node* createNode()                      //return type is a pointer to create new node
    {
        return (Node*)malloc(sizeof(Node));
    }
    
    //defined these two fns in private to access the head variable in public

    void DisplayReverse(Node *ptr)
        {
            if (ptr == NULL)
            {
                return;
            }
            DisplayReverse(ptr->next);
            printf("|%p|%d|<-",ptr->next,ptr->data);
        }

    void ReverseList(Node *current,Node *prev=NULL)
    {
        //base case This checks if the current node is NULL. If it is, it means we have reached the end of the list.
        if(current==NULL)
        {
            head=prev;
            return;
        }
        //This ensures we don’t lose the reference to the rest of the list when we reverse the pointer.
        Node *next=current->next;
        //This is the core step that reverses the direction of the linked list.
        current->next=prev;
        //recursion for next node
        ReverseList(next,current);
    }    

    public:
        Linked()
        {
            head=NULL;
        }

        int InsertBegin(int num)
        {
            Node *NODE=createNode();        //creating a node for beginning    
            NODE->data=num;
            NODE->next=head;
            head=NODE;
            return 1;
        }

        int InsertEnd(int num)
        {   
            Node *temp=head;         
            if(temp==NULL)
            {
                InsertBegin(num);
                return 1;
            }
            Node *node=createNode();           
            while(temp->next!=NULL)
            {
                temp=temp->next;             //pointing temp to last before  
            }
            node->data=num;                  //creating lastnode and data   
            node->next=NULL;                 //pointing the last node to null   
            temp->next=node;                 //connecting last node with the node which passed the while condition  
            return 1;
        }

        int InsertPosition(int num,int position)
        {
            if(position==0)                                               //beginning case
            {
                InsertBegin(num);
                return 1;
            }

            Node *temp=head;                                              //temporary pointer to traverse the list
            if(head==NULL && position<0)                                  //empty list checking 
            {
                printf("invalid position.\n");
                return 0;
            }
            Node *node=createNode();

            for(int i=0;i<position-1;i++)
            {
                if (temp->next == NULL)     // if NULL occurs before the index we mentioned, it means the given index does not exist.
                {
                    printf("Index Invalid.\n");
                    return 0;
                }
                temp = temp->next;          //else continue
            }
            node->data = num;
            node->next = temp->next;
            temp->next=node;
            return 1;
        }

        int DeleteBegin()
        {
            if(head==NULL)                                              //empty list checking 
            {
                printf("list is empty,nothing to delete");
                return 0;
            }
            Node *temp=head;                                            //pointing the temp to head initially to n
            int a=temp->data;
            head=head->next;
            free(temp);
            printf("\nsuccessfully deleted %d from the beginning of the list.\n",a);
            return a;
        }

        int DeleteEnd()
        {
            if(head==NULL)
            {
                printf("list is empty.");
                return 0;
            }
            else if(head->next == NULL) 
            {                                        // List has only one node
                DeleteBegin();
                return 1;
            }
            Node *temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            int a=temp->next->data;
            free(temp->next);
            temp->next=NULL;
            printf("\nsuccessfully deleted %d from the end of the list.\n",a);
            return a;
        }

        int DeletePosition(int position)
        {
            if(head==NULL)              //empty list checking
            {
                printf("\nList is empty.Nothing to delete.\n");
                return 0;
            }
            else if(head->next==NULL && position==0)       //list with one element checking     
            {
                DeleteBegin();
                return 1;
            }
            Node *temp=head;
            for(int i=0;i<position-1;i++)
            {
                if(temp->next->next==NULL)
                {
                    printf("\ninvalid position mentioned.\n");
                    return 0;
                }
                temp=temp->next;
            }
            int a=temp->next->data; 
            Node *del=temp->next;               
            temp->next=temp->next->next;
            free(del);
            printf("\n%d successfully deleted from the given position %d.\n",a,position);
            return a;
        }

        void display()
        {
            Node *temp=head;                //temporary pointer to traverse the list
            printf("HEAD->");
            while(temp!=NULL)
            {
                printf("|%d|%p|->",temp->data,temp->next);
                temp=temp->next;
            }
            printf("NULL\n");
        }

        int SearchElement(int num)
        {
            if(head==NULL)                  //empty list
            {
                printf("\nlist is empty.\n");
                return 0;
            }
            else if(head->next==NULL)
            {
                if(head->data==num)         //list with one element
                {
                    printf("\n%d found at the beginning.\n",num);
                    return 1;
                }
                else
                {
                    printf("\n%d not found in the list.\n",num);
                    return 0;
                }
            }
            Node *temp=head;
            int p=0;
            while(temp!=NULL)
            {
                if(temp->data==num)
                {
                    printf("\n%d found in %d index.\n",num,p);
                    return 1;
                }                
                temp=temp->next;
                p++;
            }
            printf("\n%d not found in the list.\n",num);
            return 0;
        }

        void DisplayReverse()
        {
            printf("Null<-");
            DisplayReverse(head);
            printf("Head");
        }

        void ReverseList()
        {
            ReverseList(head);
        }            
};