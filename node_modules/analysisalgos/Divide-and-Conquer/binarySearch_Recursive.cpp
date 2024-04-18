#include <iostream>
using namespace std;
bool binsearch(int *a, int l, int h, int k){
    if (l <= h)
    {
        int m = (l + h) / 2;
        if (a[m] == k){
            cout << m << endl;
            return true;
        }
        else if (a[m] < k) binsearch(a, m + 1, h, k);
        else binsearch(a, l, m, k);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "enter the key value: ";
    cin >> k;
    if (binsearch(arr, 0, n, k))
        cout << "Element Found" << endl;
    else
        cout << "Element not Found\n";
    return 0;
}