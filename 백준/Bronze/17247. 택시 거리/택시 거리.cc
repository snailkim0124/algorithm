#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            if (num) v.push_back({ i, j });
        }
    }

    cout << abs(v[0].first - v[1].first) + abs(v[0].second - v[1].second);
    
    return 0;
}