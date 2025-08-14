#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int k;
int tree[1 << 21];
int tree_size;
int res;

int go(int now) {
    if (now * 2 >= tree_size) {
        res += tree[now];
        return tree[now];
    }

    int left = go(now * 2);
    int right = go(now * 2 + 1);
    res += abs(left - right) + tree[now];
    return tree[now] + max(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    tree_size = 1 << (k + 1);

    for (int i = 2; i < tree_size; i++) {
        cin >> tree[i];
    }

    go(1);

    cout << res;
    
    return 0;
}