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

int n;
int arr[100005];
int ans = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Trie T;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        T.insert(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        // cout << T.query(arr[i]) << "\n";
        ans = max(ans, T.query(arr[i]));
    }
   
    cout << ans << "\n";

    return 0;
}