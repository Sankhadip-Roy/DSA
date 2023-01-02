#include <stdio.h>
#include <stdlib.h>
typedef struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *prev, *next;
} node;

void DoublyLinkedListTraversal(node *ptr, node *ptr1)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("%d. Element  : %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
    printf("\n");
    while (ptr1 != NULL)
    {
        printf("%d. Element  : %d\n", i, ptr1->data);
        ptr1 = ptr1->prev;
        i++;
    }
}

int main(void)
{
    node *n1, *n2, *n3, *n4;
    n1 = (node *)malloc(sizeof(node));
    n2 = (node *)malloc(sizeof(node));
    n3 = (node *)malloc(sizeof(node));
    n4 = (node *)malloc(sizeof(node));

    n1->data = 1;
    n1->next = n2;
    n1->prev = NULL;

    n2->data = 2;
    n2->next = n3;
    n2->prev = n1;

    n3->data = 3;
    n3->next = n4;
    n3->prev = n2;

    n4->data = 4;
    n4->next = NULL;
    n4->prev = n3;

    DoublyLinkedListTraversal(n1, n4);

    return 0;
}