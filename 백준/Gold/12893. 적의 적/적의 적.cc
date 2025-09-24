#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int parent[2005];
int visited[2005];
int n, m;

int findParent(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        int ap = findParent(a);
        int bp = findParent(b);

        if (ap == bp) {
            cout << 0 << "\n";
            exit(0);
        }

        if (visited[a]) {
            unionParent(visited[a], b);
        }
        else {
            visited[a] = b;
        }

        if (visited[b]) {
            unionParent(visited[b], a);
        }
        else {
            visited[b] = a;
        }

    }

    cout << 1 << "\n";


    return 0;
}