#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct comp {
    bool operator()(Node* l, Node* r) {
        if (l->freq == r->freq)
            return l->ch > r->ch;
        return l->freq > r->freq;
    }
};

Node* buildHuffmanTree(priority_queue<Node*, vector<Node*>, comp>& Q) {
    int n = Q.size();
    for (int i = 1; i < n; i++) {
        Node* z = getNode('\0', 0, nullptr, nullptr);
        Node* x = Q.top(); Q.pop();
        Node* y = Q.top(); Q.pop();
        z->left = x;
        z->right = y;
        z->freq = x->freq + y->freq;
        Q.push(z);
    }
    return Q.top();
}

void encode(Node* root, string str, unordered_map<char, string> &huff) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huff[root->ch] = str;
    }
    encode(root->left, str + "0", huff);
    encode(root->right, str + "1", huff);
}

int main() {
    unordered_map<char, int> freq;
    char ch;
    int f, n;
    
    cout << "Enter the no. of characters: ";
    cin >> n;
    cout << "Enter characters and their frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> ch >> f;
        freq[ch] = f;
    }
    
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    
    Node* root = buildHuffmanTree(pq);
    
    unordered_map<char, string> huff;
    encode(root, "", huff);
    
    vector<pair<char, string>> sorted(huff.begin(), huff.end());
    sort(sorted.begin(), sorted.end());
    cout << "\nHuffman Codes are : " << endl;
    for (auto pair: sorted) {
        cout << pair.first << " - " << pair.second << endl;
    }
    
    return 0;
}
