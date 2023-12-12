#include<stdio.h>
#define max 100
void merge_sort(int array[],int beg,int end);
void quick_sort(int array[],int beg,int end);
int partition(int array[],int beg,int end);
void merge(int array[],int beg,int mid,int end);
void main(){
    int array[max],len,choice;
    printf("\nEnter the size:");
    scanf("%d",&len);
    printf("\nenter the elements of array:");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nBefore sorting:");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",array[i]);
    }
    do
    {
        printf("\nEnter your choice:");
        printf("\n1.merge sort");
        printf("\n2.quick sort");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            merge_sort(array,0,len-1);
            printf("\tsorted array:");
            for (int i = 0; i < len; i++)
            {
                printf("%d\t",array[i]);
            }
            break;
        case 2:
            quick_sort(array,0,len-1);
            for (int i = 0; i < len; i++)
            {
                printf("%d\t",array[i]);
            }
            
            break;
        case 3:
            printf("\nexiting");
            break;
        default:
            printf("\ninvalid choice");
            break;
        }
    } while (choice!=3);
    
}
void merge_sort(int array[],int beg,int end){
    int mid;
    if (beg<end)
    {
        mid = (beg+end)/2;
        merge_sort(array,beg,mid);
        merge_sort(array,mid+1,end);
        merge(array,beg,mid,end);
    }
    
}
void merge(int array[],int beg,int mid,int end){
    int temp[max],i = beg,j = mid +1,index = beg,k=0;
    while ((i<=mid) && (j<=end))
    {
        if (array[i]<array[j])
        {
            temp[index] = array[i];
            i++; 
        }
        else{
            temp[index] = array[j];
            j++;
        }
        index++;
    }
    if (i>mid)
    {
        while (j<=end)
        {
            temp[index] = array[j];
            index++;
            j++;
        }
    }
    else{
        while (i<=mid)
        {
            temp[index]= array[i];
            index++;
            i++;
        }
    }
    while (k<index)
    {
        array[k]= temp[k];
        k++;
    }
}
void quick_sort(int array[],int beg,int end){
    int pos;
    if (beg<end)
    {
        pos = partition( array, beg, end);
        quick_sort(array,beg,pos - 1);
        quick_sort(array,pos+1,end);
    }
}
int partition(int array[],int beg,int end){
    int left,loc;
    int right;
    int temp;
    int flag =1;
    left = loc = beg;
    right = end;
    if (flag != 0)
    {
        while ((array[loc]<array[right]) && (loc != right) )
        {
            right -- ;
            if (loc == right)
            {
                flag = 0;
            }
            if (array[loc] > array[right])
            {
                temp = array[loc];
                array[loc] = array[right];
                array[right] = temp;
                loc = right;
            }
        }
        if (flag!=0)
        {
            while ((array[loc]>array[left]) && (loc!=left))
            {
                left++;
                if (loc == left)
                {
                    flag = 0;
                }
                if (array[loc] < array[left])
                {
                    temp = array[loc];
                    array[loc] = array[left];
                    array[left] = temp;
                    loc = left;
                }
            }
        }
    }
 return loc;   
}