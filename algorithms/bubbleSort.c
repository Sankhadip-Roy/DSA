#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// compare the two nearest numbers if earlier is greater then swap with the latter do until the end of the array . will get max at the end . then do the rest for other elements expect the last one.
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = 1;
        printf("%d..\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}
int main(void)
{
    int A[] = {1, 2, 5, 6, 12, 54};
    int n = sizeof(A) / sizeof(int);
    printf("n=%d\n", n);
    printArray(A, n);
    bubbleSort(A, n);
    printArray(A, n);

    return 0;
}