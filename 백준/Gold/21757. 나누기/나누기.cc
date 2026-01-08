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
ll arr[100005], pref[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pref[i] = pref[i - 1] + arr[i];
	}

	// 4등분 가능?
	if (pref[n] % 4 != 0) {
		cout << 0 << "\n";
		exit(0);
	}

	ll div = pref[n] / 4;
	ll cnt1 = 0; // div
	ll cnt2 = 0; // div * 2배
	ll res = 0;

	for (int i = 1; i < n; i++) {
		if (pref[i] == div * 3) {
			res += cnt2;
		}
		if (pref[i] == div * 2) {
			cnt2 += cnt1;
		}
		if (pref[i] == div) {
			cnt1++;
		}
	}

	cout << res << "\n";

	
	return 0;
}