// Some problem in deleting but in youtube video it was right though code is same ->https://youtu.be/Ltk9L3ohr5A
#include <stdio.h>
#include <conio.h>

int isEmpty();
int isFull();
void insert(int, int);
int getHighestPriority();
int deleteHighestPriority();
void display();

struct priorityQueue
{
    int ele;
    int priority;
} pq[5];

int rear = -1;

main()
{
    int ch, p, ele;
    do
    {
        printf("\n1.insert\n2.gtHighestPriority\n3.deleteHighestPriority\n4.Display\n5.Exit");
        printf("\n\nEnter your choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (isFull())
                printf("\npriority queue is full");
            else
            {
                printf("\nEnter element to insert: ");
                scanf("%d", &ele);
                printf("\nEnter priority: ");
                scanf("%d", &p);
                insert(ele, p);
            }
            break;
        case 2:
            if (isEmpty())
                printf("\nPriority queue is empty");
            else
            {
                p = getHighestPriority();
                printf("\nHighest priority = %d", p);
            }
            break;
        case 3:
            if (isEmpty())
                printf("\nPriority queue is empty");
            else
            {
                ele = deleteHighestPriority();
                printf("\n%d is deleted", ele);
            }
            break;
        case 4:
            if (isEmpty())
                printf("\npriority queue is empty");
            else
                display();
            break;
        }
    } while (ch != 5);
    return 0;
}

int isEmpty()
{
    if (rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == 4)
        return 1;
    else
        return 0;
}

void insert(int ele, int p)
{
    rear = rear + 1;
    pq[rear].ele = ele;
    pq[rear].priority = p;
}

int getHighestPriority()
{
    int i, p = -1;
    if (!isEmpty())
    {
        for (i = 0; i <= rear; i++)
        {
            if (pq[i].priority > p)
                p = pq[i].priority;
        }
    }
    return p;
}

int deleteHighestPriority()
{
    int i, j, p, ele;
    p = getHighestPriority();
    for (int i = 0; i <= rear; i++)
    {
        if (pq[i].priority == p)
        {
            ele = pq[i].ele;
            break;
        }
    }
    if (i < rear)
    {
        for (j = i; j < rear; j++)
        {
            pq[j].ele = pq[j + 1].ele;
            pq[j].priority = pq[j + 1].priority;
        }
    }
    rear = rear - 1;
    return ele;
}

void display()
{
    int i;
    printf("\n Priority queue = ");
    for (int i = 0; i <= rear; i++)
    {
        printf("| ele = %d - priority = %d |", pq[i].ele, pq[i].priority);
    }
}