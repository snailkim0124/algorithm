#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int c;
ll arr[50005];
ll pref[50005];
ll mod_cnt[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> c;
	while (c--) {
		memset(arr, 0, sizeof(arr));
		memset(pref, 0, sizeof(pref));
		memset(mod_cnt, 0, sizeof(mod_cnt));

		ll d, n;
		ll cnt = 0;
		cin >> d >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			pref[i] = pref[i - 1] + arr[i];
			mod_cnt[pref[i] % d]++;
		}

		cnt += mod_cnt[0];
		for (int i = 0; i < d; i++) {
			if(mod_cnt[i]) cnt += (mod_cnt[i] * (mod_cnt[i] - 1)) / 2;
		}

		cout << cnt << "\n";

	}
	
	return 0;
}