#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Node {
    map<string, Node*> nxt;
};

struct Trie {
    Node* root;
    Trie() { root = new Node(); }

    void insert(const vector<string>& v) {
        Node* node = root;
        for (const auto& s : v) {
            if (!node->nxt.count(s)) {
                node->nxt[s] = new Node();
            }
            node = node->nxt[s];
        }
    }

    void dfs(int depth, Node* node) {
        for (auto& it : node->nxt) {
            for (int i = 0; i < depth; i++) {
                cout << "--";
            }
            cout << it.first << "\n";
            dfs(depth + 1, it.second);
        }
    }

    void print() {
        dfs(0, root);
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    Trie T;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<string> v(k);
        for (int j = 0; j < k; j++) {
            cin >> v[j];
        }

        T.insert(v);
    }

    T.print();
   
    

    return 0;
}