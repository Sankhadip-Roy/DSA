#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// with the first element compare the lowest then swap and same for the rest
void selectionSort(int *A, int n)
{
    int indexOfmin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfmin])
            {
                indexOfmin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfmin];
        A[indexOfmin] = temp;
    }
}

int main(void)
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(A) / sizeof(int);
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}