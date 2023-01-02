// WRONG CODE
#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertMaxHeap(int *A, int n, int value)
{
    n = n + 1;
    A[n] = value;
    int i = n, parent, temp;
    while (i > 1)
    {
        parent = (i / 2);
        // printf("%d", parent);
        if (A[parent] < A[i])
        {
            temp = A[parent];
            A[parent] = A[i];
            A[i] = temp;
            i = parent;
        }
        else
            return;
    }
}

int main(void)
{
    int A[100] = {70, 50, 40, 45, 35, 39, 16, 10, 9};
    int n = 9;
    printArray(A, n);
    insertMaxHeap(A, n, 60); // Ans - 70 60 40 45 50 39 16 10 9 35
    printArray(A, n + 1);

    return 0;
}