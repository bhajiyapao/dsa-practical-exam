#include<stdio.h>
#include<string.h>
#define size 100
int top = -1;
char stack[size];
void push(char exp);
char pop();
void main(){
    char exp[size],temp;
    int flag = 1;
    printf("\nenter an expression:");
    fgets(exp,size,stdin);
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
       else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                flag = 0;
            }
             else{
            temp = pop();
            if (exp[i] == ')' &&(temp=='[' || temp == '{'))
            {
                flag = 0;
            }
            else if (exp[i] == '}' && (temp == '[' || temp == '('))
            {
                flag = 0;
            }
            else if (exp[i] == ']' && (temp == '{' || temp == '('))
            {
                flag = 0;
            }
        }
        }
    }
       if (top >= 0 )
        {
            flag = 0;
        }
        if (flag == 0)
        {
            printf("\ninvalid expression");
        }
        else{
            printf("\nvalid expression");
        }
}
void push(char exp){
    if (top == size -1)
    {
        printf("\nstack is full");
    }
    else
    {
        top++;
        stack[top]= exp;
    }
}
char pop(){
    char val;
    if (top == -1)
    {
        printf("\nstack is empty");
    }
    else{
        val = stack[top];
        top--;
        return val;
    }
}