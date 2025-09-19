#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll t;
vector<ll> tree;

bool cmp(pll a, pll b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

void update(int node, int s, int e, int idx) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[node]++;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx);
    update(node * 2 + 1, mid + 1, e, idx);
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

    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<pll> v(n);
        vector<ll> vy;

        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h + 1));
        tree.assign(tree_size, 0);
        map<ll, ll> mpy; // 좌표 압축

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            vy.push_back(v[i].second);
        }

        sort(all(v), cmp);
        sort(all(vy), greater<>());

        for (int i = 0; i < n; i++) {
            mpy[vy[i]] = i;
        }

        ll ans = 0;
        for (auto [x, y] : v) {
            ans += query(1, 0, n - 1, 0, mpy[y]);
            update(1, 0, n - 1, mpy[y]);
        }

        cout << ans << "\n";
    }

    return 0;
}