#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

int isEmpty(struct node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) // when computer heap will be full then p won't create
        return 1;
    else
        return 0;
}

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
        printf("Stack Overflow\n");
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// which side is null in linked list that is the lower side of the stack

int pop(struct node **top)
{
    if (isEmpty(*top))
        printf("Stack underflow");
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
        ptr = ptr->next;
    if (ptr != NULL)
        return ptr->data;
    else
        return -1;
}

int stackTop(struct node *top)
{
    return top->data;
}

int stackBottom(struct node *top)
{
    struct node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    top = push(top, 78);
    top = push(top, 8);
    top = push(top, 7);
    top = push(top, 71);
    linkedListTraversal(top);

    // int element = pop(&top);
    // printf("popped element is: %d\n", element);

    // for (int i = 1; i <= 4; i++)
    // {
    //     printf("value at position %d is : %d\n", i, peek(i));
    // }
    printf("value at top: %d\n", stackTop(top));
    printf("value at bottom: %d\n", stackBottom(top));

    return 0;
}