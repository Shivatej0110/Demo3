#include<iostream>
using namespace std;
class node
{
    public:
    int info;
    node *next;
}*list;
node *create()
{
    node *z;
    z=new node;
    return z;
}
void insert_beg(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=x;
        p->next=p;
        list=p;
    }
    else
    {
        while(p->next!=list)
        {
            p=p->next;
        }
        q=create();
        q->info=x;
        q->next=list;
        p->next=q;
        list=q;
    }
}
void insert_end(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=x;
        p->next=p;
        list=p;
    }
    else
    {
        while(p->next!=list)
        {
            p=p->next;
        }
        q=create();
        q->info=x;
        q->next=p->next;
        p->next=q;
    }
}
void insert_after(int after,int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        cout<<"\n LInked list is empty";
    }
    else if(p->next==list)
    {
        cout<<"\n Can not perform operation";
    }
    else
    {
        while(p->next!=list)
        {
            if(after==p->info)
            {
                q=create();
                q->info=x;
                q->next=p->next;
                p->next=q;
            }
            p=p->next;
        }
    }
}
void display()
{
    node *p;
    p=list;
    while(p->next!=list)
    {
        cout<<p->info<<"\t";
        p=p->next;
    }
    cout<<p->info;
}
int main()
{
    int x,ch,after;
    do
    {
        cout<<"\n Enter your choice";
        cout<<"\n 1:Insert beg\n2:Insert end\n3:INsert After\n4:display\n5:Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\n Enter any element";
            cin>>x;
            insert_beg(x);
            break;
            case 2:
            cout<<"\n Enter any element";
            cin>>x;
            insert_end(x);
            break;
            case 3:
            cout<<"\n Enter after element";
            cin>>after;
            cout<<"\n Enter any element";
            cin>>x;
            insert_after(after,x);
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            break;
        }
    } while (ch!=5);
    return 0;
}