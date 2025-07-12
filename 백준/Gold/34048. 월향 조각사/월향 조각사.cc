#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
ll arr[200005];
ll ldp[200005];
ll rdp[200005];
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	ldp[0] = min(arr[0], 1LL);
	for (int i = 1; i < n; i++) {
		ldp[i] = min(ldp[i - 1] + 1, arr[i]);
	}

	rdp[n - 1] = min(arr[n - 1], 1LL);
	for (int i = n - 2; i >= 0; i--) {
		rdp[i] = min(rdp[i + 1] + 1, arr[i]);
	}

	for (int i = 0; i < n; i++) {
		res += min(ldp[i], rdp[i]);
	}
	cout << res;
	
	return 0;
}