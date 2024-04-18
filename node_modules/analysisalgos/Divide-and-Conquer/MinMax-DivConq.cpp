#include <bits/stdc++.h>
using namespace std;
void MinMaxDAC(vector<int> &A, int i, int j, int &max, int &min)
{
    if (i == j)
    {
        max = A[i];
        min = A[i];
    }
    if (i == j - 1)
        if (A[i] < A[j])
        {
            max = A[j];
            min = A[i];
        }
        else
        {
            max = A[i];
            min = A[j];
        }
    else
    {
        int mid = (i + j) / 2;
        int LMax, LMin, RMax, RMin;
        MinMaxDAC(A, i, mid, LMax, LMin);
        MinMaxDAC(A, mid + 1, j, RMax, RMin);
        if (LMax > RMax)
            max = LMax;
        else
            max = RMax;
        if (LMin < RMin)
            min = LMin;
        else
            min = RMin;
    }
}
int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int max = arr[0], min = arr[0];
    MinMaxDAC(arr, 0, n - 1, max, min);
    cout << "Max: " << max << " Min: " << min << endl;
}