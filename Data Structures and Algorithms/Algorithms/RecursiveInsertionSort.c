#include <stdio.h>

void rec_insertion(int arr[], int n)
{
    // When the elements are all over
    if (n <= 1)
        return;

    // sorting n-1 elements
    rec_insertion(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && last < arr[j]) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;

    printf("\nAfter performing Insertion sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = { 10, 14, 3, 8, 5, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    rec_insertion(arr, n);

    return 0;
}
