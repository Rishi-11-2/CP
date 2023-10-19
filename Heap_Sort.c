#include <stdio.h>
void buildHeap(int arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
        maxHeapify(arr, n, i);
}
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int x = arr[largest];
        arr[largest] = arr[i];
        arr[i] = x;
        maxHeapify(arr, n, i);
    }
}
int main()
{
    int arr[] = {9, 8, 7, 2, 3, 4};
    int n = 6;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = arr[i];
        arr[i] = arr[0];
        arr[0] = x;
        maxHeapify(arr, i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}