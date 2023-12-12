#include<stdio.h>
#define max 10
int queue[max];
int rear = -1;
int top = -1;
void enqueue(int val);
int dequeue();
int peek();
void display();
void main(){
    int choice,val;
    do
    {
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.peek");
        printf("\n4.display");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter a val:");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if (val == -1)
            {
                printf("\nempty list");
            }
            else
            {
                printf("value deleted :%d",val);
            }
            break;
        case 3:
            val =  peek();
            if (val == -1){
                printf("\nempty list");
            }
            else
            {
                printf("\nthe top:%d",val);
            }
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
        } while (choice!=5);
}
void enqueue(int val){
    if (rear == max-1 && top == 0)
    {
        printf("\nqueue overflow");
    }
    else if (top == -1 && rear == -1)
    {
        top = rear = 0;
        queue[rear] = val;
    }
    else if (rear == max -1 && top !=0)
    {
        rear = 0;
        queue[rear] = val;
    }
    else
    {
       rear++;
       queue[rear] = val;   
    }
}
int dequeue(){
    int val;
    if (rear == -1 && top == -1)
    {
        return -1;
    }
    else if  (top == rear)
    {
        top = rear = -1;
        val  = queue[top];
        return val;
    }
    else
    {
        val = queue[top];
        if (top == max -1)
        {
            top = 0;
        }
        else
        {
            top++;
        }
        return val;
    }
    
}
void display(){
    if (top == -1 && rear == -1)
    {
        printf("\nempty queue");
    }
    else if (top<rear)
    {
        for (int i = top; i <= rear; i++)
        {
            printf("%d\t",queue[i]);
        }
        
    }
    else
    {
        for (int i = top; i < max; i++)
        {
            printf("%d\t",queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d\t",queue[i]);
        }
    }   
}
int peek(){
    if (top == -1 && rear == -1)
    {
        printf("\nqueue is empty");
        return -1;
    }
    else
    {
        return queue[top];
    }
}