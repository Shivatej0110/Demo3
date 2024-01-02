#include<iostream>
#define max 50
using namespace std;
class stack
{
    public:
    int item[max],top;
    void create();
    void push(int);
    int pop();
};
void stack::create()
{
    top=-1;
}
void stack::push(int x)
{
    if(top==max-1)
    {
        cout<<"\n Stack is full";
    }
    else
    {
        top++;
        item[top]=x;
    }
}
int stack::pop()
{
    int r;
    if(top==-1)
    {
        cout<<"\n Stack is empty";
        return 0;
    }
    else
    {
        r=item[top];
        top--;
        return r;
    }
}
int main()
{
    int i=0,t=0;
    char exp[50],r;
    stack s;
    s.create();
    cout<<"\n Enter any Expression";
    cin>>exp;
    while(exp[i]!='\0')
    {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
        {
            s.push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
        { 
            
            
            r=s.pop();
            if((r=='(')!=(exp[i]==')')||(r=='[')!=(exp[i]==']')||(r=='{')!=(exp[i]=='}'))
            {
                t=1;
                break;
            }
            
        }
        i++;
    }
    if(s.top!=-1 || t==1)
    {
        cout<<"\n Expression is Invalid";
    }
    else
    {
        cout<<"\n Expression is Valid";
    }
    return 0;
}