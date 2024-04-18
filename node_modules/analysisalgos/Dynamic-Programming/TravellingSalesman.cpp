#include <bits/stdc++.h>
using namespace std;
#define V 5
int tsp(int g[][V],int s){
    vector<int>c;int mp=INT_MAX;
    for(int i=0;i<V;i++) if(i!=s) c.push_back(i);
    do{
        int cpw=0, k=s;
        for(int i=0;i<c.size();i++){
            cpw+=g[k][c[i]];
            k=c[i];
        }
        cpw+=g[k][s];
        mp=min(mp, cpw);
    }while(next_permutation(c.begin(),c.end()));
    return mp;
}
int main(){
    int graph[V][V];
    // = {
    //     {0, 2, 7, 9, 6},
    //     {5, 0, 9, 7, 4},
    //     {3, 5, 0, 6, 9},
    //     {4, 5, 1, 0, 6},
    //     {7, 8, 3, 3, 0}
    // };
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>graph[i][j];
    int s=0;
    cout<<tsp(graph,s)<<"\n"<<endl;
    return 0;
}
