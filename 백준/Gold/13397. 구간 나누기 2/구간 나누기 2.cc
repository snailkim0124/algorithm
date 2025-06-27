#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[5005];
int res = 10001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 10000;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int mn = 10001, mx = 0;

		for (int i = 0; i < n; i++) {
			mn = min(mn, arr[i]);
			mx = max(mx, arr[i]);

			if (mx - mn > mid) {
				cnt++;
				mn = arr[i];
				mx = arr[i];
			}
		}

		if (cnt <= m) {
			res = min(res, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		
	}
	
	cout << res;

	return 0;
}