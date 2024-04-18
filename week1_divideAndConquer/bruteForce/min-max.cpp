#include<iostream>
using namespace std;

 
 
 void min_max(int a[],int n)
{
    int min=a[0];
    int max=a[0];

    for(int i=0;i<n;i++)
    {
        if(a[i]<=min)
        {
            min=a[i];
        }
        else
        {
            max=a[i];
        }

    }    
    
    cout<<"max is "<<max;
    cout<<"min is "<<min;


        
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
    
    min_max(a,n);



}