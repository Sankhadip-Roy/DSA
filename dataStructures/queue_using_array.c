#include <stdio.h>
#include <stdlib.h>
#define MAX 4

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
        printf("This Queue is full\n");
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
void enqueue_Kth(struct queue *q, int k, int val) // WBUT 2015
{
    if (isFull(q))
        printf("This Queue is full\n");
    q->r++;
    for (int c = 4 - 1; c >= k - 1; c--)
        q->arr[c + 1] = q->arr[c];
    q->arr[k - 1] = val;
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
        printf("This Queue is empty\n");
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = MAX;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    // printf("Dequeuing element %d\n", dequeue(&q));
    // printf("Dequeuing element %d\n", dequeue(&q));
    // printf("Dequeuing element %d\n", dequeue(&q));
    // enqueue(&q, 45);
    // enqueue(&q, 45);
    // enqueue(&q, 45);

    if (isEmpty(&q))
        printf("Queue is empty\n");
    if (isFull(&q))
        printf("Queue is full\n");

    return 0;
}
