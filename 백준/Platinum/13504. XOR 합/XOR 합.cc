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
    Node* nxt[2];

    Node() {
        nxt[0] = nxt[1] = NULL;
    }
};

struct Trie {
    Node* root;
    Trie() { root = new Node(); }

    void insert(int x) {
        // 비트 단위로 넣기
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!node->nxt[bit]) node->nxt[bit] = new Node();
            node = node->nxt[bit];
        }
    }

    int query(int x) {
        Node* node = root;
        int res = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->nxt[bit ^ 1]) {
                // 반대쪽 확인
                res |= (1 << i);
                node = node->nxt[bit ^ 1];
            }
            else node = node->nxt[bit];
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        Trie T;
        int n;
        int pref = 0; // 누적용
        int ans = -1;

        T.insert(0);

        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            pref ^= num;

            ans = max(ans, T.query(pref));

            T.insert(pref);
        }
        
        cout << ans << "\n";
    }
    

    return 0;
}