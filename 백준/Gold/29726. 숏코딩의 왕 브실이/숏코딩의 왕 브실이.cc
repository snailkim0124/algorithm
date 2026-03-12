#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int res = INT_MIN;
int arr[200005], pmn[200005], pmx[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
        pmn[i] = pmx[i] = arr[i];
	}

    for (int i = n - 2; i >= 0; i--) {
        pmx[i] = max(pmx[i], pmx[i + 1]);
    }

    for (int i = 1; i < n; i++) {
        pmn[i] = min(pmn[i], pmn[i - 1]);
    }

    for (int i = 0; i + (n - m) - 1 < n; i++) {
        int l = i;
        int r = i + (n - m) - 1;
        res = max({ res, arr[r] - pmn[l], pmx[r] - arr[l]});

    }

    cout << res << "\n";
    
    return 0;
}