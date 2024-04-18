#include<iostream>
#include<limits>
using namespace std;


void maxmin(int a[],int n,int &max,int &min)
{
    
}

int main()
{
     int n;
     int max=INT_MAX;
     int min=INT_MIN;
   
    cout<<"enter size of array";
    cin>>n;

   int a[n];
    cout<<"enter the elements of array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    maxmin(a,n,max,min);
}