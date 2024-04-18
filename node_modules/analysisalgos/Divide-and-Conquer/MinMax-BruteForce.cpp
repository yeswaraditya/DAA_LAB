#include<bits/stdc++.h>
using namespace std;
void bruteforceMinMax(vector<int>&a,int n,int &max,int &min){
    for(int i=0;i<n;i++){
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
}
int main(){
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    int max=arr[0],min=arr[0];
    bruteforceMinMax(arr,n,max,min);
    cout<<"Max: "<<max<<" Min: "<<min<<endl;    
}