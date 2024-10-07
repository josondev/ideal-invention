#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    list stack;
    string ip;
    cout<<"enter a string:";
    cin>>ip;
    for(char ch:ip)
    {
        if(ch=='+')
        {
            stack.DeleteEnd();
        }
        else
        {
            stack.Push(ch);
        }
    }
    stack.display();
    return 0;
}
//this involves the use of stack as we want to come from the last and check the string whose character are plus if yes we pop the previous element and plus as well.Time complexity is O(n) as it invloves iterating through the string