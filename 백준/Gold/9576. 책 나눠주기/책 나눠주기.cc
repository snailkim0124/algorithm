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
vector<pii> v;
int visited[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        v.clear();
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            pq.push({ b, a });
        }

        int cnt = 0;
        while (!pq.empty()) {
            auto [b, a] = pq.top();
            pq.pop();

            for (int i = a; i <= b; i++) {
                if (!visited[i]) {
                    visited[i] = 1;
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << "\n";
        
    }


    return 0;
}