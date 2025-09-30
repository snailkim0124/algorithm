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
ll arr[100005];
ll k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    ll left = 0;
    ll right = 0;
    ll sum = 0;
    ll cnt = 0;

    for (ll right = 0; right < n; right++) {
        sum += arr[right];
        while (left <= right && sum > k) {
            cnt += (n - right);
            sum -= arr[left];
            left++;
        }
    }

    cout << cnt << "\n";

    return 0;
}