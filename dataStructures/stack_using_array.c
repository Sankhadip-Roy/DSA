#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size, top, *arr;
};

int isEmpty(struct stack *ptr)
{
    return (ptr->top == -1);
}

int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size) - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
        printf("Stack overflow! : Can't push %d to the stack\n", val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d pushed to the stack\n", val);
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
        printf("Stack underflow! : Can't pop to the stack\n");
    else
    {
        printf("%d popped from the stack\n", ptr->arr[ptr->top]);
        ptr->top--;
    }
}

int peak(struct stack *sp, int i)
{
    if (sp->top - i + 1 < 0 || i <= 0)
        return 0;
    else
        return sp->arr[sp->top - i + 1];
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int main(void)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 34);
    push(s, 89);
    push(s, 90);
    push(s, 76);

    // if (isEmpty(s))
    //     printf("The stack is empty\n");
    // else
    //     printf("The stack isn't empty\n");
    // if (isFull(s))
    //     printf("The stack is full\n");
    // else
    //     printf("The stack isn't full\n");

    // pop(s);
    if (peak(s, 0))
        printf("%d\n", peak(s, 0));
    else
        printf("Invalid Index\n");
    // printf("%d\n", stackTop(s));
    // printf("%d\n", stackBottom(s));
    return 0;
}