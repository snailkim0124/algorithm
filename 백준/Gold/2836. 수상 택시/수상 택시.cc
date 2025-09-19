#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m;
vector<pll> neg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x > y) neg.push_back({ y, x });
    }

    sort(all(neg));

    ll start = -1;
    ll end = -1;
    ll sum = 0;

    for (int i = 0; i < neg.size(); i++) {
        if (end < neg[i].first) {
            sum += (end - start) * 2;
            start = neg[i].first;
        }

        // 완전 벗어난 상태
        end = max(end, neg[i].second);
    }
    
    sum += (end - start) * 2;

    cout << m + sum << "\n";

    return 0;
}