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
    bool end;
    map<char, Node*> nxt;
    Node() : end(false) {}
};

struct Trie {
    Node* root;
    Trie() { root = new Node(); }

    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            if (!node->nxt[c]) {
                node->nxt[c] = new Node();
            }
            node = node->nxt[c];
        }
        node->end = true;
    }

    int dfs(const string& s) {
        Node* node = root;
        int cnt = 1;
        node = node->nxt[s[0]]; // 처음은 무조건 눌러야 함

        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (node->nxt.size() > 1 || node->end) {
                cnt++;
            }
            node = node->nxt[c];
        }

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << fixed;
    cout.precision(2);

    int n;
    while (cin >> n) {
        vector<string> v(n);
        Trie T;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            T.insert(v[i]);
        }

        double sum = 0;
        for (auto it : v) {
            sum += T.dfs(it);
        }

        cout << sum / n << "\n";
    }


    return 0;
}