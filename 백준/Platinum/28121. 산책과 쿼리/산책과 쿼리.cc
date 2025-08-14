#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, q;
int parent[600005], sz[600005];
int res;

int mkrev(int a) {
    if (a > n) return a - n;
    else return a + n;
}

int findParent(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return;

    if (findParent(mkrev(a)) == a) res -= sz[a];
    if (findParent(mkrev(b)) == b) res -= sz[b];
    parent[a] = b;
    sz[b] += sz[a];

    if (findParent(mkrev(b)) == b) res += sz[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= 2 * n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    // 짝수, 홀수 산책 나누기
    while (q--) {
        int a, b;
        cin >> a >> b;
        unionParent(a, mkrev(b));
        unionParent(mkrev(a), b);
        cout << res / 2 << "\n";
    }
    

    return 0;
}