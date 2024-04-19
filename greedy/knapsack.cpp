#include<iostream>
using namespace std;

struct item{
    int weights;
    int profits;
};

bool compare(item a,item b)
{
   return  ((float)a.profits/a.weights) > ((float)b.profits/b.weights);
}

void greedyknapsack(int n,int m,item item[])
{
        sort (item,item +n,compare);

        float x[n];

        for (int  i = 0; i < n; i++)
        {
            x[i]=0;
        }

        int bucket=m;
          for (int  i = 0; i < n; i++)
        {
            if(item[i].weights>bucket)
            {
                break;
            }
            else
            {
                x[i]=1.0;
                bucket=bucket-item[i].weights;
            }
        }

int i;
        if(bucket<m && i<n)
        {
              x[i]=(float)bucket/item[i].weights;
        }

        cout << "Items Selected: " << endl;
        for(int i=0;i<n;i++)
        {
            cout<<"item"<<i+1<<"-"<<x[i]<<endl;
        }


        
}


int main()
{
    int n,m;
    cout<<"enter no of items";
    cin>>n;

item item[n];
    cout<<"enter weight and profit";

    for(int i=0;i<n;i++)
    {

      cin>>item[i].weights>>item[i].profits;
    }

    cout<<"enter the size of the bucket";
    cin>>m;
    greedyknapsack(n,m,item);
}