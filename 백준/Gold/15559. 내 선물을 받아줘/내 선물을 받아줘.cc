#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
char arr[1005][1005];
pii parent[1005][1005];

pii findParent(pii a) {
    if (a == parent[a.first][a.second]) return a;
    else return parent[a.first][a.second] = findParent(parent[a.first][a.second]);
}

void unionParent(pii a, pii b) {
    a = findParent(a);
    b = findParent(b);

    if (a != b) {
        parent[b.first][b.second] = a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            parent[i][j] = { i, j };
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pii tmp;
            if (arr[i][j] == 'N') tmp = findParent({ i - 1,j });
            else if (arr[i][j] == 'W') tmp = findParent({ i, j - 1 });
            else if (arr[i][j] == 'E') tmp = findParent({ i, j + 1 });
            else if (arr[i][j] == 'S') tmp = findParent({ i + 1, j });

            if (tmp != make_pair(i, j)) {
                unionParent(tmp, { i, j });
                cnt++;
            }
        }
    }

    cout << n * m - cnt << "\n";

    return 0;
}