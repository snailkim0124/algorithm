#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int cnt[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            cout << ((cnt[k] > 1) ? "yes" : "no") << "\n";
        }
        else if (t == 2) {
            cout << "yes\n"; // 트리에서 모든 선이 단절선
        }
    }

    return 0;
}
