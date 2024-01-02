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
        p->next=NULL;
        list=p;
    }
    else{
        q=create();
        q->info=x;
        q->next=p;
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
        p->next=NULL;
        list=p;
    }
    else{
        while(p->next!=NULL)
        {
            p=p->next;
        }
            q=create();
            q->info=x;
            q->next=NULL;
            p->next=q;
    }
}
void insert_after(int after,int x)
{
    node *p,*q;
    p=list;
    if(p==NULL||p->next->next==NULL)
    {
        cout<<"\n Can not perfom operation";
    }
    else{
        while(p->next!=NULL)
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
int remove_beg()
{
    node *p;
    int r;
    p=list;
    if(p==NULL)
    {
        cout<<"\n Linked list is empty";
        return 0;
    }
    else if(p->next==NULL){
        r=p->info;
        delete p;
        list=NULL;
        return r;
    }
    else
    {
        r=p->info;
        list=p->next;
        delete p;
        return r;
    }

}
void display()
{
    node *p;
    p=list;
    while(p!=NULL)
    {
        cout<<p->info<<"\t";
        p=p->next;
    }
}
int main(){
    int r,ch,x,after;
    do
    {
        cout<<"\n Enter your choice";
        cout<<"\n 1:Insert_beg\n 2:Insert_end\n 3:Insert_after\n4:Remove_beg\n5:Display\n 6:Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\n Enter any number";
            cin>>x;
            insert_beg(x);
            break;
            case 2:
            cout<<"\n Enter any number";
            cin>>x;
            insert_end(x);
            break;
            case 3:
            cout<<"\n enter after element";
            cin>>after;
            cout<<"\n Enter any element";
            cin>>x;
            insert_after(after,x);
            break;
            case 4:
            r=remove_beg();
            cout<<"\n Removed value is:"<<r;
            break;
            case 5:
            display();
            break;
            case 6:
            exit(0);
             break;
        }
    } while (ch!=6);
    
   return 0; 
}