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

void mergeShort(int arr[], int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeShort(arr, l, mid);
        mergeShort(arr, mid + 1, r);
        merge(arr, l, mid, r);
        // cout << "This" << endl;
        // for (int i = l; i <= mid; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        // cout << "This" << endl;
        // for (int i = mid + 1; i <= r; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
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
    mergeShort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}