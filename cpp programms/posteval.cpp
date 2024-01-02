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
        cout<<" Stack is empty";
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
    int i=0,r,val,op1,op2;
    char exp[50];
    stack s;
    //s.create();
    cout<<"\n Enter any postfix Expression";
    cin>>exp;
    s.create();
    while(exp[i]!='\0')
    {
        if(exp[i]=='+'||exp[i]=='-'|| exp[i]=='*'||exp[i]=='/'||exp[i]=='%')
        {
            op1=s.pop();
            op2=s.pop();
            switch(exp[i])
            {
                case '+':
                    val=op2+op1;
                    s.push(val);
                    break;
                case '-':
                    val=op2-op1;
                    s.push(val);
                    break;
                case '*':
                    val=op2*op1;
                    s.push(val);
                    break;
                case '/':
                    val=op2/op1;
                    s.push(val);
                    break;
                case '%':
                    val=op2%op1;
                    s.push(val);
                    break;
            }
        }
        else
        {
            s.push(exp[i]-48);
        }
        i++;
    }
    r=s.pop();
    cout<<"Your answer is:"<<r;
    return 0;
}