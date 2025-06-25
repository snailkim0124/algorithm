#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
ll arr[100005], rarr[100005];
ll pref[100005], rpref[100005];
ll mx = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		// rarr[n - i + 1] = arr[i];
	}

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + arr[i];
		// rpref[i] = rpref[i - 1] + rarr[i];
	}

	for (int i = 2; i < n; i++) {
		ll tmp = pref[n - 1] + pref[i - 1] - arr[i]; // 꿀-벌-벌
		ll rtmp = pref[n] - pref[1] - arr[i] + pref[n] - pref[i]; // 벌-벌-꿀
		ll rrtmp = pref[n - 1] - pref[i - 1] + pref[i] - pref[1]; // 벌-꿀-벌

		// cout << tmp << " : " << rtmp << " : " << rrtmp << "\n";
		mx = max(mx, max(rrtmp, max(tmp, rtmp)));
	}

	cout << mx;

	//for (int i = 1; i <= n; i++) {
	//	cout << pref[i] << " ";
	//}
	//cout << "\n";
	//for (int i = 1; i <= n; i++) {
	//	cout << rpref[i] << " ";
	//}


	return 0;
}