#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll t;
ll n, m;
ll arr[1005], brr[1005];
ll ap[1005], bp[1005];
vector<ll> va, vb;
ll res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ap[i] = ap[i - 1] + arr[i];
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> brr[i];
        bp[i] = bp[i - 1] + brr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            va.push_back({ ap[j] - ap[i - 1] });
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            vb.push_back({ bp[j] - bp[i - 1] });
        }
    }

    sort(all(va));
    sort(all(vb));

    ll left = 0;
    ll right = vb.size() - 1;

    while (left < va.size() && right >= 0) {
        ll sum = va[left] + vb[right];
        if (sum == t) {
            ll cnta = 1, cntb = 1;
            while (left + 1 < va.size() && va[left] == va[left + 1]) {
                cnta++;
                left++;
            }
            while (right - 1 >= 0 && vb[right] == vb[right - 1]) {
                cntb++;
                right--;
            }
            res += cnta * cntb;
            left++; right--;
        }
        else if (sum < t) left++;
        else right--;
    }


    cout << res << "\n";

    return 0;
}