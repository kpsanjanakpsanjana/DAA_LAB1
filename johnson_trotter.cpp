#include <iostream>
using namespace std;

#define LEFT -1
#define RIGHT 1

void printPermutation(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int getMobile(int arr[], int dir[], int n)
{
    int mobile = 0;
    int mobile_index = -1;

    for(int i = 0; i < n; i++)
    {
        if(dir[arr[i] - 1] == LEFT && i != 0)
        {
            if(arr[i] > arr[i - 1] && arr[i] > mobile)
            {
                mobile = arr[i];
                mobile_index = i;
            }
        }

        if(dir[arr[i] - 1] == RIGHT && i != n - 1)
        {
            if(arr[i] > arr[i + 1] && arr[i] > mobile)
            {
                mobile = arr[i];
                mobile_index = i;
            }
        }
    }

    return mobile;
}

void johnsonTrotter(int n)
{
    int arr[n];
    int dir[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(arr, n);

    while(true)
    {
        int mobile = getMobile(arr, dir, n);
        if(mobile == 0)
            break;

        int pos;
        for(int i = 0; i < n; i++)
            if(arr[i] == mobile)
                pos = i;

        if(dir[mobile - 1] == LEFT)
            swap(arr[pos], arr[pos - 1]);
        else
            swap(arr[pos], arr[pos + 1]);

        for(int i = 0; i < n; i++)
        {
            if(arr[i] > mobile)
                dir[arr[i] - 1] *= -1;
        }

        printPermutation(arr, n);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    johnsonTrotter(n);

    return 0;
}