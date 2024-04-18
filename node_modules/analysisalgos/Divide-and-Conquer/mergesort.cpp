#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int h)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int b[h + 1];
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (k = l; k <= h; k++)
        a[k] = b[k];
}
void mergesort(int a[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, h);
        merge(a, l, m, h);
    }
}
int main()
{
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n - 1);
    cout << "sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}