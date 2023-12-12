#include<stdio.h>
#define size 10
int queue[size];
int front = -1;
int rear = -1;
void enqueue(int val);
int dequeue();
int peek();
void display();
void main(){
    int val,choice;
    do
    {
        printf("\nqueue simulation:");
        printf("\n1.enter into queue");
        printf("\n2.delete from queue");
        printf("\n3.peek from queue");
        printf("\n4.display queue");
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value:");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
             val = dequeue();
             if (val == -1)
             {
                printf("\nqueue is empty");
             }
             else
             {
                printf("\nelement  %d is removed",val);
             }
             break;
        case 3:
            val = peek();
            if (val == -1)
            {
               printf("\nqueue is empty");
            }
            else
            {
                printf("\ntop most element is:%d",val);
            }
            break;
        case 4:
            printf("\nqueue:");
            display();
            break;
        case 5:
             printf("\nexiting program ...");
             break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice!=5);
    
}
void enqueue(int val){
    if (rear == size-1)
    {
        printf("\nqueue overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear]= val;
    }
}
int dequeue(){
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\nqueue is empty");
        return -1;
    }
    else if (front == rear)
    {
        val = queue[front];
        front = rear = -1;
        return val;
    }
    else
    {
        val = queue[front];
        front++;
        return val;
    }
}
int peek(){
if (front == -1 && rear == -1)
{
    printf("\nqueue is empty");
    return -1;
}
else
{
    return queue[front];
}
}
void display(){
    if (front == -1 && rear == -1)
    {
        printf("\nqueue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    
}