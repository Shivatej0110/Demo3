#include<iostream>
#define max 5
using namespace std;
class stack
{
    public:
    int item[max],top;
    void create();
    void insert(int);
    int remove();
    void display();
};
void stack::create()
{
    top=-1;
    cout<<"\n Stack is created";
}
void stack::insert(int x)
{
    if(top==max-1)
    {
        cout<<"\n stack is full";
    }
    else
    {
        top++;
        item[top]=x;
        cout<<"\n Element inserted";
    }
}
int stack::remove()
{
    int r;
    if(top==-1)
    {
        cout<<"\n stack is empty";
        return 0;
    }
    else
    {
        r=item[top];
        top--;
        return r;
    }
}
void stack::display()
{
    int i;
    for(i=top;i>=0;i--)
    {
       cout<<item[i]<<"\t";
    }
}
int main()
{
    int r,ch,x;
    stack s;
    do
    {
        cout<<"\n Enter your choice";
        cout<<"\n 1:Create\n2:Insert\n3:Remove\n4:Display\n5:Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            s.create();
            break;
            case 2:
            cout<<"\n Enter any element";
            cin>>x;
            s.insert(x);
            break;
            case 3:
            r=s.remove();
            cout<<"\n Removed value is:"<<r;
            break;
            case 4:
            s.display();
            break;
            case 5:
            exit(0);
            break;
        }
    } while (ch!=5);
    return 0;
}