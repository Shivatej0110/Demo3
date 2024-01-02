#include<iostream>
#define max 100
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
        cout<<"\n stack overflows";
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
        cout<<"\n stack is empty";
        return 0;
    }
    else{
        r=item[top];
        top--;
        return r;
    }
}
int main()
{
    char infix[50],post[50],r;
    int i=0,j=0;
    stack s;
    cout<<"\n Enter any infix expression";
    cin>>infix;
    s.create();
    while(infix[i]!='\0')
    {
        if(infix[i]=='('||infix[i]=='+' ||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
        {
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(s.item[s.top]!='(')
            {
                r=s.pop();
                if(r!='(')
                {
                    post[j]=r;
                    j++;
                }
            }
            s.pop();
        }
        else
        {
            post[j]=infix[i];
            j++;
        }
        i++;
    }
    if(s.top!=-1)
    {
        while(s.top!=-1)
        {
            r=s.pop();
            if(r!='(')
            {
                post[j]=r;
                j++;
            }
        }
    }
    post[j]='\0';
    cout<<"\n postfix Expression is:"<<post;
    return 0;
}