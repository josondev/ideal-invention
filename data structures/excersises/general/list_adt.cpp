#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define size 5

#cur the current index of the array

using namespace std;

class list
{
    int arr[size],cur;//good practice to keep variables in private.
    public:
        list()//constructor
            {
                cur=-1;
            }
        //methods start here   
        int insertbeg(int element);
        int insertend(int element);
        int insertposn(int element,int position);
        int deletebeg();
        int deleteend();
        int deleteposn(int position);
        void printarray();
};

    
int main()
{
    int choice,element,position;
    //declaring an object of the above defined class
    list l1;
    while(true)
    {
        cout<<"MENU\n1. Insert Beginning\n2. Insert End\n3. Insert pos \n4. Delete begining\n5. Delete End\n6. Delete pos\n7. Display\n\n";
        cout<<"your choice:"<<endl;
        cin>>choice;
        if(choice>7 && choice<0)
        {
            break;
        }            
        switch(choice)
        {
            case 1:
                cout<<"enter element to be inserted:";
                cin>>element;
                if(l1.insertbeg(element))
                    cout<<"Inserted at the beginning"<<endl;
                else
                {
                    cout<<"failed to insert"<<endl;
                }  
                break;

            case 2:
                cout<<"enter element to be inserted:";
                cin>>element;
                if(l1.insertend(element))
                    cout<<"inserted at end"<<endl;
                else
                {
                    cout<<"failed to insert"<<endl;
                } 
                break; 

            case 3:
                cout<<"enter the number to insert:";
                cin>>element;
                cout<<"enter the position to insert:";
                cin>>position;
                if(l1.insertposn(element,position))
                    {
                        cout<<"successfully inserted in position "<<position<<endl;
                    }  
                else
                    {
                        cout<<"failed to insert"<<endl;
                    } 
                break;

            case 4:                
                if(l1.deletebeg())
                {
                    cout<<"successfully deleted in beginning"<<endl;
                }   
                else
                {
                    cout<<"failed to delete"<<endl;
                } 
                break; 

            case 5:
                if(l1.deleteend())
                {
                    cout<<"successfully deleted in end"<<endl;
                }   
                else
                {
                    cout<<"failed to delete";
                } 
                break; 

            case 6:
                cout<<"enter the position to delete element:" ;
                cin>>position;
                if(l1.deleteposn(position))
                {
                    cout<<"succesfully deleted at position "<<position;
                } 
                else
                {
                    cout<<"failed to delete"<<endl;
                }   

            case 7:
                {
                    l1.printarray();
                }  
                 
        }
        
        
    }
}
//definitions start here

int list::insertbeg(int element)

    {
        //failed to insert case
        
        if(cur==size-1)
        {
            return 0;
        }

        //fresh insertion

        else if(cur==-1)
        {
            cur=0;
            arr[0]=element;
            return 1;
        }
        
        //pushing the elements forward

        else
        {
            for(int i=cur;i>=0;i--)
            {
                arr[i+1]=arr[i];
            }
            cur++;
            arr[0]=element;
            return 1;
        }
    }

int list::insertend(int element)
    {
        if(cur==size-1)
        {
            return 0;
        }
        else if(cur==-1)
        {
            cur=0;
            arr[0]=element;
            return 1;
        }
        else
        {
            arr[cur++]=element;
            return 1;
        }
    }

int list::insertposn(int element,int position)
    {

        if(cur==size-1 || cur==-1)
        return 0;

        else
            {
                for(int i=cur;i>=position;i--)
                    {
                        arr[i+1]=arr[i];
                    }
                arr[position] = element;
                cur++;
                return 1;    
            }
    }
int list::deletebeg()
    {
        int temp = 0;
        if(cur == -1)
        {
            return 0;
        }
        else
        {
            temp = arr[0];
            for(int i = 0; i <= cur; i++)
            {
                arr[i]=arr[i+1];
            }
            cur = cur - 1;
            return temp;
        }
    }

int list::deleteend()
    {
        if(cur == -1)
        {
            return 0;
        }

        else
        {
            int temp = arr[cur];
            cur --;
            return (temp);
        }
        
    }

int list::deleteposn(int position)
    {
        if(cur == -1)
        {
            return 0;
        }

        else{
            int temp = arr[position];
            for(int i = position; i <= cur; i++)
            {
                arr[i]=arr[i+1];
            }
            cur = cur - 1;
            return temp;
        }
    }

void list::printarray()
    {
            cout<<"[";
            for (int i = 0; i <= cur; i++)
            {
                cout<<arr[i];
                if (i < cur)
                {
                    cout<<",";
                }
            }
            cout<<"]"<<endl;
    }    