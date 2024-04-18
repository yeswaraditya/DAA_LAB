#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
pair<int, int> knapSack(int W, int wt[], int pro[], int n){
    if (n == 0 || W == 0)
        return make_pair(0, 0);
    if (wt[n - 1] > W)
        return knapSack(W, wt, pro, n - 1);
    pair<int, int> inc = knapSack(W - wt[n - 1], wt, pro, n - 1);
    inc.first += pro[n - 1];
    inc.second += wt[n - 1];
    pair<int, int> exc = knapSack(W, wt, pro, n - 1);
    return (inc.first > exc.first) ? inc : exc;
}
int main(){
    int n;
    cout << "Enter the number of items: "; cin >> n;
    int profit[n],weight[n];
    cout << "Enter the profits for each item:\n";
    for (int i = 0; i < n; ++i) cin >> profit[i];
    cout << "Enter the weights for each item:\n";
    for (int i = 0; i < n; ++i) cin >> weight[i];
    int W;
    cout << "Enter the maximum weight capacity: "; cin >> W;
    pair<int, int> result = knapSack(W, weight, profit, n);
    cout << "Maximum profit: " << result.first << endl;
    cout << "Total weight: " << result.second << endl;
    return 0;
}