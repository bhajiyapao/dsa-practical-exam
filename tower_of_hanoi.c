#include<stdio.h>
int movements = 0;
void tower(int number,char from,char sparse,char dest);
void main(){
    int number;
    printf("\t\tTower of hanoi simulation:\n");
    printf("\tEnter the number of the peg:\n");
    scanf("%d",&number);
    tower(number,'A','B','C');
    printf("\nthe total movements:%d",movements+1);
}
void tower(int number,char from,char sparse,char dest){
    if (number == 1)
    {
        printf("\ndisks moved from %c to %c\n",from,dest);
        return;
    }
     movements+=1;
    tower(number-1,from,sparse,dest);
    printf("\ndisks moved from %c to %c\n",from,sparse);
    movements+=1;
    tower(number-1,sparse,dest,from);
}