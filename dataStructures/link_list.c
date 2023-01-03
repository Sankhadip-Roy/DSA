#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
} node;

void LinkedListTraversal(node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("%d. Element  : %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

node *InsertAtFirst(node *head)
{
    int data;
    printf("Enter the element to insert at first: ");
    scanf("%d", &data);
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

void InsertAtIndex(node *head) // between
{
    int data, index;
    printf("Enter the index to which insert: ");
    scanf("%d", &index);
    printf("Enter the element to insert at %d position: ", index);
    scanf("%d", &data);

    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    node *p = head;
    int i = 0;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}

void InsertAfterNode(node *prevNode)
{
    int data, i;
    printf("Enter the element to insert after passed node: ");
    scanf("%d", &data);

    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    (prevNode)->next = ptr;
    ptr->next = (prevNode)->next;
}

void InsertAtEnd(node *head)
{
    int data;
    printf("Enter the element to insert at end: ");
    scanf("%d", &data);

    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

node *deleteFirst(node *head)
{
    node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

void deleteAtIndex(node *head)
{
    int index;
    printf("Enter the index to delete: ");
    scanf("%d", &index);
    node *p = head;
    node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}

void deleteAtLast(node *head)
{
    node *p = head;
    node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

void deleteAValue(node *head)
{
    int value;
    printf("Enter the key to delete: ");
    scanf("%d", &value);
    node *p = head;
    node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
}

int main(void)
{
    int n, i;
    node *head, *first, *second, *third, *fourth;
    head = (node *)malloc(sizeof(node));
    first = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    head->data = 3;
    head->next = first;
    first->data = 2;
    first->next = second;
    second->data = 4;
    second->next = third;
    third->data = 6;
    third->next = fourth;
    fourth->data = 9;
    fourth->next = NULL;

    printf("\nbefore updating....\n\n");
    LinkedListTraversal(head);
    printf("\n1.insert at first\n2.insert in between\n3.insert at end\n4.insert after node\n5.delete first\n6.delete in index\n7.delete at last\n8.delete a key\n\nenter:");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        head = InsertAtFirst(head);
        break;
    case 2:
        InsertAtIndex(head);
        break;
    case 3:
        InsertAtEnd(head);
        break;
    case 4:
        InsertAfterNode(second);
        break;
    case 5:
        head = deleteFirst(head);
        break;
    case 6:
        deleteAtIndex(head);
        break;
    case 7:
        deleteAtLast(head);
        break;
    case 8:
        deleteAValue(head);
        break;
    }

    printf("\nafter updating....\n\n");
    LinkedListTraversal(head);
    return 0;
}