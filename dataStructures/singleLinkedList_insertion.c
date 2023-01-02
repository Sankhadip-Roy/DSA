#include<stdio.h>
#include<stdlib.h>

typedef struct singlelinkedlist
{
    int value;
    struct singlelinkedlist *next;
}sl;

void create(sl **head,int ele)
{
   sl *current,*p;     //declaring nodes

   if (*head == NULL)
   {
        *head = (sl *)malloc(sizeof(sl));
        (*head)->value = ele;
        (*head)->next = NULL;
   }
   else
   {
        current = *head;

        while(current->next != NULL)
        {
            current = current->next;
        }
        p = (sl*)malloc(sizeof(sl));
        p->value = ele;
        current->next = p; 
        p->next = NULL;
    }
}
void insert(sl **head,int v)
{
    sl *current,*prev,*p;
    current = *head;

    if (current->value > v)
    {
        p = (sl*)malloc(sizeof(sl));
        p->value = v;
        p->next = current;
        *head = p;
    }
    else
    {
        while (current->next != NULL && current->value < v)
        {
            prev = current;
            current = current->next;
        }
        if(current->next != NULL)
        {
            p = (sl*)malloc(sizeof(sl));
            p->value = v;
            p->next = p;
            p->next = current;
        }
        if(current->next == NULL)
        {
            p = (sl*)malloc(sizeof(sl));
            p->value = v;
            current->next = p;
            p->next = NULL;
        } 
    }
}
void display(sl *head)
{
    if(head == NULL)
    {
       printf("\nlist is empty");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d->",head->value);
            head = head->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int n = 0,num;
    char ch;
    sl *head;
    head = NULL;
    int a[100],ele;

    printf("\n enter the input : "); 
    while(1)
    {
          
        scanf("%d",&num);
        a[n] = num;
        n++;
        scanf("%c",&ch);
        if(ch == '\n')
          break;
    }
    for(int i = 0; i<n ; i++)
    {
        create(&head,a[i]);
    }
    insert(&head,5);
    insert(&head,18);
    insert(&head,35);
    display(head);
    
    return 0;
}
