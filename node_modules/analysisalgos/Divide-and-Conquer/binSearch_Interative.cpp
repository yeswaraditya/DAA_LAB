#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cout << "enter the key value: ";
    cin >> k;
    int flag = 0;
    int l = 0, h = n;
    while (l < h)
    {
        int m = (l + h) / 2;
        if (a[m] == k)
        {
            flag = 1;
            cout << "Element found at " << m << endl;
            break;
        }
        else if (a[m] < k)
            l = m + 1;
        else
            h = m;
    }
    if (flag == 0)
        cout << "Element not found\n";
}