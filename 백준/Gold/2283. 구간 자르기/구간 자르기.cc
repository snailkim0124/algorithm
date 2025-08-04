#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, k;
ll arr[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x + 1; j <= y; j++) {
			arr[j]++;
		}
	}

	ll left = 0;
	ll right = 0;
	ll sum = 0;
	ll mx = 1000000;

	while (right <= mx) {
		if (sum == k) {
			cout << left << " " << right << "\n";
			exit(0);
		}
		else if (sum > k) {
			sum -= arr[++left];
		}
		else if (sum < k) {
			sum += arr[++right];
		}
	}

	cout << "0 0" << "\n";

	return 0;
}