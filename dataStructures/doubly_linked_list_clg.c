#include <stdio.h>
#include <stdlib.h>
typedef struct doublyLinkedList
{
    int value;
    struct doublyLinkedList *pre;
    struct doublyLinkedList *next;
} dl;
void create(dl **header)
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    dl *current, *p;
    current = *header;
    if (*header == NULL)
    {
        *header = (dl*)malloc(sizeof(dl));
        (*header)->value = val;
        (*header)->next = NULL;
        (*header)->pre = NULL;
    }
    else
    {
        while (current->next != NULL){
            current = current->next;
            }
        p = (dl*)malloc(sizeof(dl));
        p->value = val;
        current->next=p;
        p->pre = current;
        p->next = NULL;
    }
}
void display(dl **header)
{
	dl *ptr=*header;
	while (ptr != NULL)
	{
		printf("%d->", ptr->value);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
void insertBefore(dl **header)
{
    int target;
    printf("Enter target: ");
    scanf("%d", &target);
    dl *current, *p, *prev;
    current = *header;
    int val;
    printf("Enter the element to insert: ");
    scanf("%d", &val);
    if (current->value == target)
    {
        p = (dl *)malloc(sizeof(dl));
        p->value = val;
        p->next = current;
        current->next=NULL;
        p->pre = NULL;
    }
    else
    {
        while (current->value != target)
        {
            prev = current;
            current = current->next;
        }
        p = (dl *)malloc(sizeof(dl));
        p->value = val;
        p->next = current;
        current->pre=p;
        prev->next=p;
        p->pre = prev;
    }
}
void insertAfter(dl **header, int target)
{
    dl *current, *p;
    current = *header;
    int val;
    printf("Enter the element to insert: ");
    scanf("%d", &val);
    while (current->value != target)
    {
        current = current->next;
    }
    if (current->next != NULL)
    {
        p = (dl *)malloc(sizeof(dl));
        p->value = val;
        p->next = current->next;
        p->pre = current;
        current->next=p;
    }
    else
    {
        p = (dl *)malloc(sizeof(dl));
        p->value = val;
        p->next = NULL;
        p->pre = current;
        current->next=p;
    }
}
void delete (dl **header, int target)
{
    dl *current, *prev;
    current = *header;
    if (current->value == target)
    {
        *header = current->next;
        free(current);
    }
    else
    {
        while (current->value != target)
        {
            prev = current;
            current = current->next;
        }
        if (current->next != NULL)
        {
            prev->next = current->next;
            free(current);
        }
        else
        {
            prev->next = NULL;
            free(current);
        }
    }
}
int main(void)
{
    dl *header = NULL;
    
    int n, val, target;
    while (1)
    {
        printf("\n1.create 2.display 3.insert before 4.insert after 5.delete 6.exit\n");
        printf("\nchoose: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            
            create(&header);
            break;
        case 2:
            display(&header);
            break;
        case 3:
            insertBefore(&header);
            break;
        case 4:
            printf("Enter target: ");
            scanf("%d", &target);
            insertAfter(&header, target);
            break;
        case 5:
            printf("Enter target: ");
            scanf("%d", &target);
            delete (&header, target);
            break;
        case 6:
            return 0;
            break;
        }
    }
    return 0;
}
