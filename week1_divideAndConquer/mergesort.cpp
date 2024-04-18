#include<iostream>
using namespace std;

void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int b[high+1];

    while(low<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }

    }
    
    if (i>mid)
    {
        while(j<=high) 
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }

    for(k=low;k<=high;k++)
    {
        a[k]=b[k];
    }

}

void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);

    }
}


int  main()
{
    int n;
    cout<<"enter size of array";
    cin>>n;

   int a[n];
    cout<<"enter the elements of array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    
    mergesort(a,0,n-1);
    cout<<"sorted"<<endl;
for(int i=0;i<n;i++)
    {
        cout<<a[i];

    }


}