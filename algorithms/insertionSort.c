#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// from the second element , if the second element is less than the the first one then swap then the rest same procedure place it in its palce
void insertionSort(int *A, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main(void)
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(A) / sizeof(int);
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}