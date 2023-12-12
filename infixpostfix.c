#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char st[MAX];
int top = -1;
void push(char st[], char);
char pop(char st[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);
void main()
{
char infix[100], postfix[100];
printf("\n Enter any infix expression : ");
gets(infix);
strcpy(postfix, "");
InfixtoPostfix(infix, postfix);
printf("\n The corresponding postfix expression is : ");
puts(postfix);
}
void InfixtoPostfix(char source[],char target[]){
    int i = 0,j=0;
    char temp;
    strcpy(target,"");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st,source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while (top != -1 && (source[i] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("\nIncorrect");
                exit(1);
            }
            temp = pop(st);
            i++;
        }
        else if (isalpha(source[i]) || isdigit(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1 && (st[top] != '('))  && (getPriority(st[top]) > getPriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st,source[i]);
            i++;
        }
        else
        {
            printf("\nincorrect expression");
            exit(1);
        }
    }
       while (top != -1 && st[top] != '(')
        {
            target[j] = pop(st);
            j++;
        }
    target[j] = '\0';   
}
int getPriority(char exp){
    if (exp == '/' || exp == '*' || exp == '%')
    {
        return 2;
    }
    else if (exp == '-' || exp == '+' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char stack[],char exp){
    if (top == MAX-1)
    {
        printf("\nfull stack");
    }
    else
    {
        top++;
        stack[top] = exp;
    }
}
char pop(char stack[]){
  
  return stack[top--];
    
}