#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int i, j;
void printArray(int *arr, int n)
{
    printf("\n|");
    for (i = 0; i < n; i++)
        printf(" %d |", arr[i]);
}

int maximum(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void countSort(int *arr, int n)
{

    int max = maximum(arr, n);
    int *count = (int *)calloc((max + 1), sizeof(int));
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    i = j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
}
int main(void)
{
    int n, *arr;
    printf("Enter the size of the array to sort: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    countSort(arr, n);
    printArray(arr, n);
    return 0;
}