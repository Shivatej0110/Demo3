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
    cout<<"\n Queue is created";
}
void queue::insert(int x)
{
    if(front==0&&rear==max-1||front==rear+1)
    {
        cout<<"\n Queeu is full";
    }
    else
    {
        if(rear==-1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%max;
        }
        item[rear]=x;
    }
}
int queue::remove()
{
    int r;
    if(front==-1)
    {
        cout<<"\n Queue is empty";
        return 0;
    }
    else
    {
        r=item[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%max;
        }
        return r;
    }
}
void queue::display()
{
    int i;
    for(i=front;i!=rear;i=(i+1)%max)
    {
        cout<<item[i]<<"\t";
    }
    cout<<item[i];
}
int main()
{
    int r,ch,x;
    queue q;
    do
    {
        cout<<"\n Enter yopur choice";
        cout<<"\n 1:Create\n 2:Insert\n3:Remove\n4:Display\n5:Exit";
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
            cout<<"\n Removed value is:"<<r;
            break;
            case 4:
            q.display();
            break;
            exit(0);
            break;

        }
    } while (ch!=5);
    return 0;
}