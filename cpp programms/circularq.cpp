#include<iostream>
#define max 5
using namespace std;
class queue
{
    public:
    int item[max],front,rear;
    void create();
    void insert(int);
    int remove();
    void display();
};
void queue::create()
{
    front=rear=-1;
    cout<<"\n queue is created";
}
void queue::insert(int x)
{
    if(front==0 && rear==max-1||front==rear+1)
    {
        cout<<"\n queue is full";
    }
    else{
        if(rear==front)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%max;
        }
        item[rear]=x;
        cout<<"element inserted";
    }
}
int queue::remove()
{
    int r;
    if(front==rear)
    {
        cout<<"\n Queue is empty";
        return 0;
    }
    else{
        r=item[front];
        if(rear==front)
        {
            rear=front=-1;
        }
        else
        {
            front=(front+1)%max;
        }
        return 0;
    }
}
void queue::display()
{
    int i;
    for(i=front;i!=rear;i=(i+1)%max)
    {
        cout<<item[i]<<"\t";
    }
    cout<item[rear];
}
int main()
{
    int r,ch,x;
    queue q;
    do
    {
        cout<<"\n Enter your choice";
        cout<"\n1:create\n2:Insert\n3:Remove\nDisplay\n5:Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            q.create();
            break;
            case 2:
            cout<<"\n Enter any element";
            cin>>x;
            q.insert(x);
            break;
            case 3:
            r=q.remove();
            cout<<"\n Removed vlue is:"<<r;
            break;
            case 4:
            q.display();
            break;
            case 5:
            exit(0);
            break;
        }
    } while (ch!=5);
    return 0;
}