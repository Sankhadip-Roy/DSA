#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// two sorted array compare both arrays 1st num then arrange in a new array and do the same for the the rest
// in one array devide it and do the above
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[high + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main(void)
{
    int A[] = {12, 54, 65, 7, 23, 9, 1, 456};
    int n = sizeof(A) / sizeof(int);
    int l = 0, h = n - 1;
    printArray(A, n);
    mergeSort(A, l, h);
    printArray(A, n);
    return 0;
}