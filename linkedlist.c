#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start= NULL;
struct node *createlist(struct node*);
struct node *insertbeg(struct node*);
struct node *insertend(struct node*);
struct node *insertbefore(struct node*);
struct node *insertafter(struct node*);
struct node *deletebeg(struct node*);
struct node *deleteend(struct node*);
struct node *deletenode(struct node*);
struct node *deleteafter(struct node*);
struct node *display(struct node*);
struct node *deletelist(struct node*);
struct node *sort(struct node*);
void main(){
    int choice;
    do
    {
        printf("\nenter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start = createlist(start);
            break;
        case 2:
            start = insertbeg(start);
            break;
        case 3:
            start = insertend(start);
            break;
        case 4:
            start = insertbefore(start);
            break;
        case 5:
            start = insertafter(start);
            break;
        case 6:
             start = deletebeg(start);
             break;
        case 7:
            start = deleteend(start);
            break;
        case 8:
             start = deletenode(start);
             break;
        case 9:
             start = deleteafter(start);
             break;
        case 10:
             start = display(start);
             break;
        case 11:
             start = deletelist(start);
             break;
        case 12:
             start = sort(start);
             break;
        case 13:
             printf("\nexiting...");
             break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice != 13);
    
}
struct node *createlist(struct node *start){
    struct node *ptr,*nn;
    int val;
    printf("\nenter -1 to exit");
    printf("\nEnter the data:");
    scanf("%d",&val);
    while(val != -1)
    {
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
  
    if (start == NULL)
    {
        nn->next = NULL;
        start = nn;
    }
    else
    {
        ptr = start;
        while (ptr!= NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = nn;
        nn->next = NULL;
    }
      printf("\nEnter data:");
      scanf("%d",&val);
    } 
    return start;
}
struct node *insertbeg(struct node *start){
    int val;
    struct node *nn;
    nn= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value:");
    scanf("%d",&val);
    nn->data = val;
    nn->next = start;
    start = nn;
    return start;   
}
struct node *insertend(struct node *start){
    struct node *nn,*ptr;
    int val;
    ptr = start;
    printf("\nEnter value:");
    scanf("%d",&val);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = nn;
    return start;
}
struct node *insertbefore(struct node *start){
    struct node *nn,*ptr,*pp;
    int val,before;
    nn = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&val);
    nn->data = val;
    printf("\nEnter value for insertion before:");
    scanf("%d",&before);
    ptr = start;
    pp = start;
    while (ptr->data!= val)
    {
        pp = ptr;
        ptr = ptr->next;
    }
    nn->next = ptr;
    pp->next = nn;
    return start;
}
struct node *insertafter(struct node *start){
    struct node *nn,*ptr,*pp;
    int val,after;
    printf("\nEnter val:");
    scanf("%d",&val);
    printf("\nEnter after:");
    scanf("%d",&after);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    pp = start;
    ptr = start;
    while (pp->data != val)
    {
        pp = ptr;
        ptr = ptr->next;
    }
    nn->next = ptr;
    pp->next = nn;
    return start;
}
struct node *deletebeg(struct node *start){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
     ptr = start;
    start = start->next;
    free(ptr);
    }
    return start;
}
struct node *deleteend(struct node *start){
    struct node *ptr,*pp;
    if (start == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        ptr = start;
        pp = start;
        while (ptr->next != NULL)
        {
            pp = ptr;
            ptr = ptr->next;
        }
        pp->next = NULL;
        free(ptr);
    }
    return start;
}
struct node *deleteafter(struct node *start){
    struct node *ptr,*pp;
    int val;
    printf("\nEnter val:");
    scanf("%d",&val);
    if (start == NULL)
    {
        printf("\nList is empty");
    }
    else{
        ptr = start;
        pp = start;
        while (pp->data!=val)
        {
            pp = ptr;
            ptr = ptr->next;
        }
        pp->next = ptr->next;
        free(ptr);
    }
    return start;
}
struct node *deletenode(struct node *start){
    struct node *ptr,*pp;
    int val;
    printf("\nEnter value:");
    scanf("%d",&val);
    if (start == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        ptr = start;
        pp = start;
        while (ptr->data != val)
        {
            pp =ptr;
            ptr = ptr->next;
        }
        pp->next = ptr->next;
    }
    return start;
}
struct node *display(struct node *start){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty");
    }
    else{
          ptr = start;
          while (ptr!= NULL)
          {
            printf("%d\t",ptr->data);
            ptr = ptr->next;
          }
    }
    return start;
}
struct node *deletelist(struct node *start){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is deleted");
    }
    else
    {
        ptr = start;
        while (ptr!=NULL)
        {
            printf("\nThe data deleted is:%d",ptr->data);
            start = deletebeg(start);
            ptr = ptr->next;
        }
    }
    return start;
}
struct node *sort(struct node *start){
    struct node *ptr1,*ptr2;
    int temp;
    ptr1 = start;
  
    while (ptr1!=NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2!=NULL)
        {
            if (ptr1->data > ptr2->data)
            {
               temp = ptr1->data;
               ptr1->data = ptr2->data;
               ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;   
}