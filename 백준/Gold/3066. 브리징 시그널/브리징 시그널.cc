#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
int arr[40005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        int n;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> dp;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            if (it == dp.end()) dp.push_back(arr[i]);
            else *it = arr[i];
        }

        cout << dp.size() << "\n";
    }

    

    return 0;
}