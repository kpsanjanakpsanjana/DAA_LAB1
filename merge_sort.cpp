#include <iostream>
using namespace std;

void merge(int arr[], int small, int mid, int large)
{
    int x = small;
    int y = mid + 1;
    int z = 0;
    int temp[100];

    while(x <= mid && y <= large)
    {
        if(arr[x] < arr[y])
            temp[z++] = arr[x++];
        else
            temp[z++] = arr[y++];
    }

    while(x <= mid)
        temp[z++] = arr[x++];

    while(y <= large)
        temp[z++] = arr[y++];

    for(int i = small, k = 0; i <= large; i++, k++)
        arr[i] = temp[k];
}

void divide(int arr[], int small, int large)
{
    if(small < large)
    {
        int mid = (small + large) / 2;

        divide(arr, small, mid);
        divide(arr, mid + 1, large);
        merge(arr, small, mid, large);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    divide(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}