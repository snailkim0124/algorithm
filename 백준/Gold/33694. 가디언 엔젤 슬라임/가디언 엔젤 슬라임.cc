#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, x;
vector<ll> v;
vector<pll> vse;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        ll a, b, c, t;
        cin >> a >> b >> c >> t;
        ll s = t + (x + a - 1) / a;
        ll mx = ((c + a - 1) / a) * a;

        if (mx < x) continue; // 최대보다 작은 경우

        ll up_cnt = (mx - x) / a;
        ll down_cnt = (mx - x) / b;
        ll e = s + up_cnt + down_cnt;

        v.push_back(s);
        v.push_back(e + 1);

        vse.push_back({ s, e });
    }

    // 좌표 압축
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    vector<ll> pref(v.size() + 1, 0);

    for (int i = 0; i < vse.size(); i++) {
        auto [s, e] = vse[i];

        int sidx = lower_bound(all(v), s) - v.begin();
        int eidx = lower_bound(all(v), e + 1) - v.begin();

        pref[sidx]++;
        pref[eidx]--;
    }

    // 차분 배열
    ll cnt = 0;
    ll now = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        now += pref[i];
        if (now >= 3) {
            cnt += (v[i + 1] - v[i]);
        }
    }

    cout << cnt << "\n";


    return 0;
}