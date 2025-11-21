#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, q;
int arr[300005];
int pref[300005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + arr[i];
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << pref[r] - pref[l - 1] << "\n";
	}

	return 0;
}