#include<bits/stdc++.h>
using namespace std;


void maxmin(vector<int> &a,int i,int j,int &max,int &min)
{
     if(i==j)
     {
        max=a[i];
        min=a[i];
        return;

     }

     if(i==j-1)
     {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
            max=a[i];
            min=a[j];
        }
        return;
     }
     else
     {
        int mid=(i+j)/2;
        int lmax,lmin,rmax,rmin;
        maxmin(a,i,mid,lmax,lmin);
        maxmin(a,mid+1,j,rmax,rmin);
        if(lmax>rmax)
        {
            max=lmax;
        }
        else
        {
            max=rmax;
        }
        if(lmin<rmin)
        {
            min=lmin;
        }
        else
        {
            min=rmin;
        }
     }
}

int main()
{
    vector <int > arr;

     int n;
   
    cout<<"enter size of array";
    cin>>n;

    cout<<"enter the elements of array";
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);

    }

    int max=INT_MIN,min=INT_MAX;

    maxmin(arr,0,n-1,max,min);

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
}