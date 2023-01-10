#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
} node;

void LinkedListTraversal(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int linkedListLength(node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    return i;
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

node *deleteAtIndex(node *head)
{
    int index;
    printf("Enter the index to delete from 0 to %d: ", linkedListLength(head) - 1);
    scanf("%d", &index);
    if (index < 0 || index > linkedListLength(head))
        printf("ERROR: Node %d does not exist!\n", index);
    else
    {
        node *p = head;
        node *q = head->next;
        if (index == 0)
            head = deleteFirst(head);
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
            free(q);
        }
    }
    return head;
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

int MaxMinInList(node *head, int *max, int *min)
{
    node *currentNode = head;
    if (currentNode == NULL)
        return 0;
    *max = *min = currentNode->data;
    for (currentNode = currentNode->next; currentNode != NULL; currentNode = currentNode->next)
    {
        if (currentNode->data > *max)
            *max = currentNode->data;
        else if (currentNode->data < *min)
            *min = currentNode->data;
    }
    return 1;
}

int main(void)
{
    int n, i, max, min;

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

    printf("\nAlready created linked list: ");
    LinkedListTraversal(head);

    while (1)
    {
        printf("\n1.traverse linked list\n2.insert at first\n3.insert in between\n4.insert at end\n5.insert after node\n6.delete first\n7.delete in index\n8.delete at last\n9.delete a key\n10.Length of linked list\n11.max and min in linked list\n12.exit\n\nEnter:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            LinkedListTraversal(head);
            break;
        case 2:
            head = InsertAtFirst(head);
            break;
        case 3:
            InsertAtIndex(head);
            break;
        case 4:
            InsertAtEnd(head);
            break;
        case 5:
            InsertAfterNode(second);
            break;
        case 6:
            head = deleteFirst(head);
            break;
        case 7:
            head = deleteAtIndex(head);
            break;
        case 8:
            deleteAtLast(head);
            break;
        case 9:
            deleteAValue(head);
            break;
        case 10:
            printf("Linked list length: %d", linkedListLength(head));
            break;
        case 11:
            if (MaxMinInList(head, &max, &min))
                printf("max->%d,min->%d\n", max, min);
            else
                printf("link list is empty\n");
            break;
        case 12:
            printf("\nafter updating: ");
            LinkedListTraversal(head);
            return 0;
        }
    }
    return 0;
}