#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size, top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
        printf("Stack Underflow! Cannot pop from the stack\n");
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char p_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(sp, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
                return 0;
            p_ch = pop(sp);
            if (!(p_ch == '(' && exp[i] == ')' || p_ch == '{' && exp[i] == '}' || p_ch == '[' && exp[i] == ']'))
                return 0;
        }
    }
    return isEmpty(sp);
}
int main()
{
    char *exp = "{(a-b)+c+d*[e*f]}";
    if (parenthesisMatch(exp))
        printf("The parenthesis are balanced");
    else
        printf("The parenthesis are not balanced");
    return 0;
}