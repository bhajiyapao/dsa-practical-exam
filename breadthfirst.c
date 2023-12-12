#include<stdio.h>
#define max 5
void breadthfirst(int adj[][max],int visited[],int start){
    int queue[max],rear = -1,front = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear!= front)
    {
        start = queue[++front];
        if (start == 4)
        {
            printf("5\t");
        }
        else
        {
            printf("%c \t",start+65);
        }
       for (int i = 0; i < max; i++)
           {
           if (adj[start][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
           }
    }
}
void main(){
    int visited[max] = {0};
    int adj[max][max],i,j;
    printf("\nenter the adjancey matrix:\n");
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    breadthfirst(adj,visited,0);    
}