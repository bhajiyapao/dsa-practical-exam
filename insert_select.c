#include<stdio.h>
#define max 100
void insertion_sort(int array[],int len);
void selection_sort(int array[],int len);
int smallest_element(int array[],int k,int len);
int array[max];
void main(){
    int choice,len;
    printf("\nEnter the length of array:");
    scanf("%d",&len);
    printf("\nStart enterring the elements:");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nyour array on which the sort would be applied:");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",array[i]);
    }
    do
    {
        printf("\nSORTING ALGORITHM:");
        printf("\n1.insertion");
        printf("\n2.Selection");
        printf("\n3.exit");
        printf("\n4.redefine array");
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\niterations:\n");
            insertion_sort(array, len);
            printf("\nsorted array:");
            for (int i = 0; i < len; i++)
            {
                printf("%d\t",array[i]);
            }
            break;
        case 2:
           printf("\niterations:\n");
           selection_sort(array,len);
           printf("\nsorted array:");
           for (int i = 0; i < len; i++)
           {
            printf("%d\t",array[i]);
           }
        break;
        case 4:
        for (int i = 0; i < len; i++)
        {
            scanf("%d",&array[i]);
        }
        printf("\nnew array:\n");
        for (int i = 0; i < len; i++)
        {
            printf("%d\t",array[i]);
        }
        break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice!=3);
}
void insertion_sort(int array[],int len){
    int i,j,temp;
    for (int i = 1; i < len; i++)
    {
        temp = array[i];
        j = i - 1;
        while ((temp<array[j]) && (j >= 0 ))
        {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = temp;
        for (int i = 0; i < len; i++)
        {
            printf("%d\t",array[i]);
        }
        printf("\n");
        
    }
    
}
void selection_sort(int array[],int len){
    int temp,k,pos;
    for (int k = 0; k < len; k++)
    {
        pos = smallest_element(array,k,len);
        temp = array[k];
        array[k] = array[pos];
        array[pos] = temp;
        for (int i = 0; i < len; i++)
        {
            printf("%d\t",array[i]);
        }
        printf("\n");
    }
}
int smallest_element(int array[],int k,int len){
    int i,small = array[k],pos = k;
    for (int i = k+1; i < len; i++)
    {
        if (small>array[i])
        {
            small = array[i];
            pos = i;
        }
        
    }
    return pos;
}