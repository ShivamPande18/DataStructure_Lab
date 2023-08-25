#include<stdio.h>
#define SIZE 10

int front = 0;
int rear = 0;
int arr[SIZE];

void insert(int val)
{
    if((rear+1)%SIZE == front)
    {
        printf("Queue is full\n");
        return;
    }

    rear = (rear+1)%SIZE;
    arr[rear] = val;
}

int delete()
{
    if(front==rear)
    {
        printf("Queue is empty\n");
        return -99999;
    }

    front = (front+1)%SIZE;
    return(arr[front]);
}

void display()
{
    int i=0;
    for(i = (front+1)%SIZE; i!= rear; i = (i+1)%SIZE)
    {
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[i]);
}

int main()
{
    insert(10);
    display();
    insert(20);
    display();
    insert(30);
    display();
    insert(40);
    display();
    delete();
    delete();
    display();

    return 0;
}
