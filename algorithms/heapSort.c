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

void swap(int *A, int i, int j)
{
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// void swap(int *a, int *b)
// {
//     int temp = *b;
//     *b = *a;
//     *a = temp;
// }

void maxHeapify(int *A, int n, int i)
{
    int largest = i;
    int l = (2 * i);
    int r = (2 * i) + 1;
    if (l <= n && A[l] > A[largest])
    {
        largest = l;
    }
    if (l <= n && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(A, largest, i);
        maxHeapify(A, n, largest);
    }
}

// void maxHeapify(int A[], int n, int i)
// {
//     if (n == 1)
//     {
//         printf("Single element in the heap");
//     }
//     else
//     {
//         // Find the largest among root, left child and right child
//         int largest = i;
//         int l = 2 * i + 1;
//         int r = 2 * i + 2;
//         if (l < n && A[l] > A[largest])
//             largest = l;
//         if (r < n && A[r] > A[largest])
//             largest = r;

//         // Swap and continue heapifying if root is not largest
//         if (largest != i)
//         {
//             swap(&A[i], &A[largest]);
//             maxHeapify(A, n, largest);
//         }
//     }
// }

void heapSort(int *A, int n)
{
    {
        int temp;
        for (int i = n / 2; i >= 1; i--) // build max heap
        {
            maxHeapify(A, n, i);
        }
        for (int i = n; i >= 1; i--) // deleting
        {
            swap(A, 1, i);
            maxHeapify(A, i - 1, 1);
        }
    }
}

int main(void)
{
    int A[] = {4, 6, 1, 2, 45, 12, 40};
    int n = 7;
    printArray(A, n);
    heapSort(A, n);
    printArray(A, n);
    return 0;
}