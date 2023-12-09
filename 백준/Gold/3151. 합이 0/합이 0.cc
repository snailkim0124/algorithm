#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, MIN = 5000000001, x, y, z;
ll a[10005];
ll cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1 ; j < n - 1; j++) {
			ll sum = a[i] + a[j];
			ll low = lower_bound(a + (j + 1), a + n, sum * -1) - a;
			ll up = upper_bound(a + (j + 1), a + n, sum * -1) - a;
			cnt += up - low;
		}
	}

	cout << cnt;


	return 0;
}