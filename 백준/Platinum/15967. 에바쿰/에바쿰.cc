#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> a;
vector<ll> tree;

ll init(int node, int s, int e) {
    if (s == e) return tree[node] = a[s];
    else {
        int mid = (s + e) / 2;
        return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
    }
}

void update(int node, int s, int e, int l, int r, ll val) {
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        for (int i = s; i <= r; i++) {
            tree[node] += val;
        }
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return tree[node];

    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, q1, q2;
    cin >> n >> q1 >> q2;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);
    init(1, 1, n);

    ll q = q1 + q2;

    while (q--) {
        ll cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll l, r;
            cin >> l >> r;
            //cout << "ans : ";
            cout << query(1, 1, n, l, r) << "\n";
        }
        else if (cmd == 2) {
            ll s, e, l;
            cin >> s >> e >> l;
            update(1, 1, n, s, e, l);
        }
    }

    
    return 0;
}