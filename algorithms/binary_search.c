#include <stdio.h>
int BinarySearch(int arr[], int num, int size)
{
    int low = 0, mid, high = size - 1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(void)
{
    int arr[] = {1, 3, 5, 8, 12, 34, 67, 89, 112, 234}, size = sizeof(arr) / sizeof(int), num = 34, index = BinarySearch(arr, num, size);
    if (index >= 0)
        printf("%d no. is present in the %d th index", num, index);
    else
        printf("%d no. not present", num);
    return 0;
}