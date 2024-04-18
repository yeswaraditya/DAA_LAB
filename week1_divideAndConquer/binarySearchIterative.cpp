#include<iostream>
using namespace std;

int main()
{
    int n,key;
    cout<<"enter size of array";
    cin>>n;
    int a[n];

    cout<<"enter elements";

    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }
    cout<<"enter the key value";
    cin>>key;
    
    int low=0,high=n-1;
    int mid;

    while (low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            cout<<"element found at index"<<mid;
            break;
        }
        
        else if (key<a[mid])
        {
            high=mid-1;

        }

    
        else
        {
            low=mid+1;
        }
    }
    if(low> high)
    {
        cout<<"element not found";
    }

    
}