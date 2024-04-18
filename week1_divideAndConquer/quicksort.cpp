#include<iostream>
using namespace std;


int  partition(int a[],int low,int high)
{
   int pivot=a[low];
   int i=low;
   int j=high;

while(i<j)
{
   while(a[i]<pivot)
   {
    i++;
   }
   
   while(a[j]>pivot)
   {
    j--;
   }

   
   if( i<j)
   {
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
   }
}  
   return j;
} 

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {

     int location=partition(a,low,high);
     quicksort(a,low,location-1);
     quicksort(a,location+1,high);
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
    
    quicksort(a,0,n-1);
    cout<<"sorted"<<endl;
for(int i=0;i<n;i++)
    {
        cout<<a[i];

    }


}