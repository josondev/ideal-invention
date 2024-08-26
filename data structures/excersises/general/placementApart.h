#include <stdio.h>
#include <stdlib.h>

class List
{
    private:
        typedef struct Node
        {
            int data;
            struct Node* next;
        }Node;

        Node* head;
        
        Node* createNode(void)
        {
            return (Node*)malloc(sizeof(Node));
        }

        Node* getHead(void)
        {
            return head;
        }

        void freeList(void) //function to free memory.
        {
            Node* tmp;
            while (head != NULL)
            {
                tmp = head;
                head = head->next;
                free(tmp);
            }
        }

    public:
        List(void): head(NULL) {} //constructor function.

        ~List() //Destructor to clean up memory.
        {
            freeList();
        }

        void InsertAscending(int num)
        {
            Node* tmp = head;
            Node* node = createNode();
            node->data = num;
            if (head == NULL)
            {
                node->next = NULL;
                head = node;
                return;
            }

            if (num < head->data)
            {
                node->next = head;
                head = node;
                return;
            }

            while (true)
            {
                if (tmp->next == NULL || num < tmp->next->data)
                {
                    node->next = tmp->next;
                    tmp->next = node;
                    return;
                }
                tmp = tmp->next;
            }
        }

        void Merge(List* l1, List* l2)
        {
            freeList();
            Node* head1 = l1->getHead();
            Node* head2 = l2->getHead();
            int greater;
            
            while (head1 != NULL && head2 != NULL)
            {
                if (head1->data > head2->data)
                {
                    greater = head1->data;
                    head1 = head1->next;
                }

                else
                {
                    greater = head2->data;
                    head2 = head2->next;
                }
                InsertAscending(greater);
            }

            while (head1 != NULL)
            {
                InsertAscending(head1->data);
                head1 = head1->next;
            }

            while (head2 != NULL)
            {
                InsertAscending(head2->data);
                head2 = head2->next;
            }
        }

        void display(void)
        {
            Node* tmp = head;
            printf("HEAD -> ");
            while (tmp != NULL)
            {
                printf("%d -> ", tmp->data);
                tmp = tmp->next;
            }
            printf("NULL\n");
        }
};