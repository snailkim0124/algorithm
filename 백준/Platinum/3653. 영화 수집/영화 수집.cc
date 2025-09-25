#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> tree;
vector<ll> pos;

void update(int node, int s, int e, int idx, ll val) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[node] += val;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);
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
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int h = (int)ceil(log2(n + m));
        int tree_size = (1 << (h + 1));
        tree.assign(tree_size, 0);
        pos.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pos[i] = m + i;
            update(1, 1, n + m, pos[i], 1);
        }

        int top = m;

        for (int i = 1; i <= m; i++) {
            int k;
            cin >> k;

            int now = pos[k];
            cout << query(1, 1, n + m, 1, now - 1) << " ";

            update(1, 1, n + m, now, -1);
            update(1, 1, n + m, top, 1);

            pos[k] = top;
            top--;
        }
        cout << "\n";
    }

    return 0;
}
