#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
ll arr[200005];
map<ll, ll> mp;
ll cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	mp[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];

		if (mp.count(arr[i] - k)) {
			cnt += mp[arr[i] - k];
		}
		mp[arr[i]]++;
	}

	cout << cnt << "\n";
	
	return 0;
}