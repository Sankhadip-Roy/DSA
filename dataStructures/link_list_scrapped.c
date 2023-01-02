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
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// node *InsertAtFirst(node *element)
// {
//     int data;
//     printf("Enter the element to insert at first: ");
//     scanf("%d", &data);
//     node *ptr = (node *)malloc(sizeof(node));
//     ptr->data = data;
//     ptr->next = element;
//     return ptr;
// }

void InsertAfterNode(node *element)
{
    int data, i;
    printf("Enter the element to insert after node: ");
    scanf("%d", &data);
    printf("Enter after which node you want to insert: ");
    scanf("%d", &i);
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    ptr->next = (element + i - 1)->next;
    (element + i - 1)->next = ptr;
}
// void InsertAtEnd(node *element)
// {
//     int data;
//     printf("Enter the element to insert at end: ");
//     scanf("%d", &data);
//     node *ptr = (node *)malloc(sizeof(node));
//     ptr->data = data;
//     node *p = element;
//     while (p->next != NULL)
//     {
//         p = p->next;
//     }
//     p->next = ptr;
//     ptr->next = NULL;
// }

// void InsertAtIndex(node *element) // between
// {
//     int data, index;
//     printf("Enter the index to which insert: ");
//     scanf("%d", &index);
//     printf("Enter the element to insert at %d position: ", index);
//     scanf("%d", &data);
//     node *ptr = (node *)malloc(sizeof(node));
//     ptr->data = data;
//     node *p = element;
//     int i = 0;
//     while (i != (index - 1))
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->next = p->next;
//     p->next = ptr;
// }

int main(void)
{
    int n, i;
    node *element;
    element = (node *)malloc(n * sizeof(node));
    printf("No of elements in linkedlist: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d no. element of linked list: ", i + 1);
        fflush(stdin);
        scanf("%d", &((element + i)->data));
        // if (i != n - 1)
        //     (element + i)->next = (element + i + 1);
        // else
        //     (element + i)->next = NULL;
    }

    printf("\nbefore updating....\n\n");
    // LinkedListTraversal(element);
    printf("\nupdating....\n\n");

    // element = InsertAtFirst(element);
    // InsertAtIndex(element);
    // InsertAtEnd(element);
    // InsertAfterNode(element);
    for (int i = 0; i < n; i++)
    {
        printf("%lu\n", (element + i)->data);
    }

    // LinkedListTraversal(element);

    return 0;
}