#include<iostream>
#include<algorithm>
using namespace std;
struct Item {
    int weight;
    int profit;
};
bool compare(Item a, Item b) {
    return ((float)a.profit / a.weight) > ((float)b.profit / b.weight);
}
void GreedyKnapsack(int n, int m, Item items[]) {
    sort(items, items + n, compare);
    int i;
    float x[n];
    for ( i = 0; i < n; i++)
        x[i] = 0;
    int u = m;
    for ( i = 0; i < n; i++) {
        if (items[i].weight > u)
            break;
        else {
            x[i] = 1.0;
            u = u - items[i].weight;
        }
    }
    if (u < m && i < n)
        x[i] = (float)u / items[i].weight;
    cout << "Items Selected: " << endl;
    for (int i = 0; i < n; i++)
        cout << "Item " << i + 1 << "- " << x[i] << endl;
}
int main() {
    int n, m;
    cout << "Enter the n.of items: ";
    cin >> n;
    Item items[n];
    cout << "Enter the weight-profit:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
    }
    cout << "Enter the size: ";
    cin >> m;
    GreedyKnapsack(n, m, items);
    return 0;
}

