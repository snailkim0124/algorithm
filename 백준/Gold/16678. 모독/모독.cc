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
ll sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    ll start = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= start) continue;
        start++;
        if (start < arr[i]) {
            sum += arr[i] - start;
        }
    }

    cout << sum << "\n";

    return 0;
}