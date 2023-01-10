// college lab
// have to add to the power ^
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

int top = -1, flag = 0;
int s[MAX];

int pop()
{
    return s[top--];
}

int push(int ele)
{
    int num;
    if (flag == 1)
    {
        num = pop();
        s[++top] = ele + 10 * num;
    }
    else if (flag == 0)
    {
        s[++top] = ele;
        flag = 1;
    }
}

int main(void)
{
    char *pofx, ch, temp;
    int i = 0, op1, op2;
    pofx = (char *)malloc(100 * sizeof(char));
    printf("Enter the postfix expression: ");
    fgets(pofx, 100, stdin);
    while ((ch = pofx[i++] != '\n'))
    {
        if (isdigit(ch))
            push(ch - '0');
        else if (ch == ' ')
            flag = 0;
        else
        {
            flag = 0;
            op2 = pop();
            op1 = pop();
            // upper operand divides lower one
            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            }
        }
    }
    printf("Result = %d\n", s[top]);
    return 0;
}