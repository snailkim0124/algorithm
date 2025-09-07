#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Trie {
    struct Node {
        int end;
        int nxt[26];
        Node() {
            end = 0;
            fill(nxt, nxt + 26, -1);
        }
    };

    vector<Node> trie;
    Trie() { trie.emplace_back(); }

    void insert(const string& s) {
        int node = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[node].nxt[idx] == -1) {
                trie[node].nxt[idx] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].nxt[idx];
        }
        trie[node].end++;
    }

    bool startsWith(const string& s) {
        int node = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[node].nxt[idx] == -1) return false;
            node = trie[node].nxt[idx];
        }
        return true;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Trie T;
    int n, m, cnt = 0;
    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        T.insert(s);
    }

    while (m--) {
        string s;
        cin >> s;
        cnt += T.startsWith(s);
    }

    cout << cnt << "\n";

    return 0;
}