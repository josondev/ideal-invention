#include "roundrobin.h"

int time_alloted;

int main()
{
    int choice,time_alloted,time;
    List l1;
    cout<<"enter time to be alloted for each process:";
    cin>>time_alloted;
    cout<<"\n1)Insert Process\n2)Execute\n3)exit\n"<<endl;
    cout<<"enter your choice:";
    cin>>choice;
    while(1)
    {
        if(choice>3 || choice<1)
        {
            cout<<"enter a proper choice between 1 and 3 inclusive:";
            cin>>choice;
        }
        else if(choice==3)
        {
            return 0;
        }
        else if(choice==1)
        {
            cout<<"enter the time to insert it in the queue:";
            cin>>time;
            l1.InsertBegin(time);
            l1.Display();
        }
        else if(choice==2)
        {
            l1.Execute();
            l1.Display();
        }
        cout<<"\n1)Insert Process\n2)Execute\n3)exit\n"<<endl;
        cout<<"enter your choice:";
    }
}