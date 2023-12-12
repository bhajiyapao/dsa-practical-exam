#include<stdio.h>
#define max 5
void depthfirstsearch(int adj[][max],int visited[],int start){
    int stack[max];
    int top = -1,i;
    printf("%c->\t",start+65);
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1)
    {
        start = stack[top];
        for (int i = 0; i < max; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
              stack[++top] = i;
              printf("%c ->\t",i+65);
              visited[i] = 1;
              break;
            }
        }
        if (top == max)
        {
            top --;
        }
        
    }
    
}
void main(){
    int adj[max][max],visited[max] ={0},i,j;
    printf("\nenter matrix\n");
    for ( i = 0; i < max; i++)
    {
        for ( j = 0; j < max; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    depthfirstsearch(adj,visited,0);
}