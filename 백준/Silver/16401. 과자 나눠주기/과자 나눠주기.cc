#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int m, n;
int arr[1000005];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int left = 1;
	int right = arr[n - 1];

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt >= m) {
			left = mid + 1;
			res = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}