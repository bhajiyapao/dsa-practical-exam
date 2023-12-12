#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start = NULL;
struct node *createinsert(struct node*);
struct node *deleteelement(struct node*);
struct node *peek(struct node*);
void display(struct node*);
void main(){
    int choice;
    do
    {
        printf("\n1.create insert");
        printf("\n2.delete element");
        printf("\n.3.peek");
        printf("\n4.display");
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start = createinsert(start);
            break;
        case 2:
            start = deleteelement(start);
            break;
        case 3:
             start = peek(start);
             break;
        case 4:
             display(start);
             break;
        case 5:
            printf("\nexiting..");
            break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice != 5);
}
struct node *createinsert(struct node *start){
    int val,prio;
    struct node *p,*ptr;
    printf("\nenter data:");
    scanf("%d",&val);
    printf("\nenter priority:");
    scanf("%d",&prio);
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->priority=prio;
    if (start == NULL || ptr->priority < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next!= NULL && p->priority<ptr->priority)
        {
            p  = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
}
struct node *deleteelement(struct node *start){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nqueue is empty");
    }
    else
    {
        ptr = start;
        start = start->next;
        printf("\nthe data deleted:%d",ptr->data);
        free(ptr);
    }
    return start;
}
struct node *peek(struct node *start){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nqueue is empty");
    }
    else
    {
        ptr = start;
        printf("\nthe topmost priority element:%d",ptr->data);
    }
    return start;
}
void display(struct node *start){
    struct node *p;
    if (start == NULL)
    {
        printf("\nnothing to display");
    }
    else
    {
        p = start;
        while (p!=NULL)
        {
            printf("%d[%d]\t",p->data,p->priority);
            p = p->next;
        }
    }
}