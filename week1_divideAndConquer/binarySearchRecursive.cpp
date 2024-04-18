#include<iostream>
using namespace std;

int binarySearchRecursive(int a[],int low,int high,int key)
{
     if (low == high)
     {
        if(a[low]==key)
        {
            return low;
        }
        else
        {
            return -1;

        }

       
     }
      else
        {
            int mid=(low+high)/2;

            if(key==a[mid])
            {
                return mid;
            }
            else if(key<a[mid])
            {
               return binarySearchRecursive(a,low,mid-1,key);
            }
            else
            {
                return binarySearchRecursive(a,mid+1,high,key);
            }

            
        }
}




int main()
{
    int n,key;
    cout<<"enter size of array";
    cin>>n;

   int a[n];
    cout<<"enter the elements of array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    cout<<"enter element to search";
    cin>>key;
    int result =binarySearchRecursive(a,0,n,key);

    if(result == -1)
    {
        cout<<"element not found";

    }
    else
    {
        cout<<"element found at "<<result;
    }
}

