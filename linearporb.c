#include<stdio.h>
#define size 10
int hashtable[size];
void insert_element(int hashtable[],int key);
void display(int hashtable[]);
int delete(int hashtable[],int key);
int search(int hashtable[],int key);
void main(){
    int choice,key;
    for (int i = 0; i < size; i++)
    {
        hashtable[i] = -1;
    }
    do
    {
        printf("\nhashing simulation:");
        printf("\n1.insert key");
        printf("\n2.display key");
        printf("\n3.search key");
        printf("\n4.delete key");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter key:");
            scanf("%d",&key);
            insert_element(hashtable,key);
            break;
        case 2:
           display(hashtable);
           break;
        case 3:
         printf("\nEnter key:");
         scanf("%d",&key);
         key  = search(hashtable,key);
         if (key == -1)
         {
            printf("\nkey not found");
         }
         else{
            printf("\nkey founded at %d",key);
         }
        break;
        case 4:
            printf("\nenter key to delete:");
            scanf("%d",&key);
            key = delete(hashtable,key);
            if (key == -1)
            {
                printf("\nkey is not their");
            }
            else{
                printf("\nkey deleted from index:%d",key);
            }
            break;
        case 5:
           printf("\nexiting..");
           break;
        default:
           printf("\ninvalid choice.");
            break;
        }
    } while (choice!=5);
    
}
void insert_element(int hashtable[],int key){
    int div,func,i=0;
    div = key % size;
   while (i<=size)
   {
    
        func = (div + i) % size;
        if (hashtable[func] == -1)
        {
            hashtable[func] = key;
            break;
        }
     if (i == size)
        {
        printf("couldnt insert key");
        break;
        }
        i++;
    }
 
}
void display(int hashtable[]){
    printf("index\tkey\t\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d",i,hashtable[i]);
        printf("\n");
    }
}
int search(int hashtable[],int key){
    int func,div,i=0,keypos;
    div = key % size;
    while (i<=size)
    {
        if (i == size)
        {
            printf("\ncould not insert a key.");
            return -1;
        }
        func = (div + i) % size;
        if (hashtable[func] == key )
        {
            keypos = func;
            return keypos;
            break;
        }
        i++;
    }
}
int delete(int hashtable[],int key){
    int keypos;
    keypos = search(hashtable,key);
    if (keypos == -1)
    {
        return -1;
    }
    else{
        if (hashtable[keypos] == key)
        {
            hashtable[keypos] = -1;
            return keypos;
        }
        
    }
}
    
    
