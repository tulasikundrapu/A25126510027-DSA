#include <stdio.h>
#include <ctype.h>
#include <string.h>
int prec(char c)
{
    if (c=='^')
        return 3;
    else if (c=='*' || c=='/')
        return 2;
    else if (c=='+' || c=='-')
        return 1;
    else
        return 0;
}
void infixToPostfix(char *infix)
{
    int len=strlen(infix);
    char result[len+1];
    char stack[len]; 
    int i,j=0,top=-1;
     for(i=0;i<len;i++)
    {
       char c=infix[i];
        if(isalnum(c))
        {
            result[j++]=c;
        }
        else if(c=='(')
        {
            stack[++top]='(';
        }
        else if(c==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
                result[j++] =stack[top--];
            }
            top--;
        }
        else
        {
            while (top!=-1 &&
                   prec(c)<=(prec(stack[top])))
            {
                result[j++] =stack[top--];
            }
            stack[++top]=c;
        }
    }
    while (top!=-1)
        result[j++]=stack[top--];
    result[j]='\0';
    printf("%s\n",result);
}
int main()
{
    char infix[50];
    printf("Enter infix expression: ");
    scanf("%[^\n]s", infix);
    infixToPostfix(infix);
    return 0;
}