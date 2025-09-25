#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
vector<pll> v, vv;
priority_queue<ll, vector<ll>, greater<ll>> pq;
ll d;
ll mx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll h, o;
        cin >> h >> o;
        v.push_back({ h, o });
    }
    cin >> d;

    // d보다 큰거 제외
    for (auto [h, o] : v) {
        if (abs(h - o) <= d) {
            if (h > o) swap(h, o);
            vv.push_back({ h, o });
        }
    }

    // 끝점기준으로 정렬
    sort(all(vv), [](pll a, pll b) {
        return a.second < b.second;
    });

    //for (auto [h, o] : vv) {
    //    cout << h << " : " << o << "\n";
    //}

    for (int i = 0; i < vv.size(); i++) {
        while (!pq.empty() && pq.top() < vv[i].second - d) pq.pop();
        pq.push(vv[i].first);
        mx = max(mx, (ll)pq.size());
    }

    cout << mx << "\n";

    return 0;
}