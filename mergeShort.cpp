#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int leftSize = (m - l) + 1;
    int rightSize = r - m;
    int L[leftSize], R[rightSize];

    int k = 0;
    for (int i = l; i <= m; i++)
    {
        L[k] = arr[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = arr[i];
        k++;
    }

    int i = 0, j = 0, curr = l;
    while (i < leftSize && j < rightSize)
    {
        if (L[i] <= R[j])
        {
            arr[curr] = L[i];
            i++;
        }
        else
        {
            arr[curr] = R[j];
            j++;
        }
        curr++;
    }

    while (i < leftSize)
    {
        arr[curr] = L[i];
        i++;
    }
    while (j < rightSize)
    {
        arr[curr] = R[j];
        j++;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge(arr, 0, 3, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}