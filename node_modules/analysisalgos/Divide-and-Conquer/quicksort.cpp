#include <iostream>
using namespace std;
int partition(int a[], int l, int h)
{
    int piv = a[l];
    int i = l + 1;
    int j = h;
    while (i <= j)
    {
        while (a[i] <= piv && i <= j)
            i++;
        while (a[j] > piv && i <= j)
            j--;
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;
}
void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int loc = partition(a, l, h);
        quicksort(a, l, loc - 1);
        quicksort(a, loc + 1, h);
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
    quicksort(a, 0, n - 1);
    cout << "sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}