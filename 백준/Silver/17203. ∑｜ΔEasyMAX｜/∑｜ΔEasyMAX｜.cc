#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, q;
int arr[1005], pref[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + abs(arr[i] - arr[i - 1]);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        
        cout << pref[b] - pref[a] << "\n";
    }

    return 0;
}