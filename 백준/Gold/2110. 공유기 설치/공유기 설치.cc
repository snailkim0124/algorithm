#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, c;
int arr[200005];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int left = 0;
	int right = arr[n - 1];

	while (left <= right) {
		int mid = (left + right) / 2;
		int now = arr[0];
		int cnt = 1;

		for (int i = 1; i < n; i++) {
			if (arr[i] - mid >= now) {
				cnt++;
				now = arr[i];
			}
		}

		if (cnt >= c) {
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