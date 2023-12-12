#include<stdio.h>
#include<string.h>
#define max 100
void push(int val);
int pop();
int gettype(char exp);
int stack[max];
int top = -1;
void main(){
    char exp[max],val,result,len,i,op1,op2;
    printf("\nEnter prefix expression:");
    fgets(exp,max,stdin);
    len = strlen(exp);
    for ( i = len - 1; i >= 0 ; i--)
    {
        switch (gettype(exp[i]))
        {
        case 1:
            val = exp[i] - '0';
            push(val);
            break;
        case 2:
           op1 = pop();
           op2 = pop();
           switch (exp[i])
           {
           case '+':
              result = op1 +op2;
            break;
           case '-':
             result = op1 - op2;
             break;
          case '*':
            result = op1 * op2;
            break;
          case '/':
             result = op1 / op2;
             break;
           }
           push(result);
           break;

        }
    }
    printf("\nthe result is:%d",stack[0]);
}
void push(int val){
    if (top == max-1)
    {
        printf("\nstack is full");
    }
    else
    {
        top++;
        stack[top] = val;
    }   
}
int pop(){
    return stack[top--];
}
int gettype(char exp){
    if (exp == '+' || exp == '-' || exp == '/' || exp == '*') 
    {
        return 2;
    }
    else
    {
        return 1;
    }
    
}