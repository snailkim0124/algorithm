#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;
queue<pll> q;
unordered_set<ll> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        q.push({ num, num });
        s.insert(num);
    }

    ll cnt = 0;
    ll res = 0;
    while (!q.empty() && cnt < k) {
        auto [origin, now] = q.front();
        q.pop();

        for (auto next : { now - 1, now + 1 }) {
            if (!s.count(next)) {
                q.push({ origin, next });
                s.insert(next);
                res += abs(next - origin);
                cnt++;
                if (cnt == k) break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}