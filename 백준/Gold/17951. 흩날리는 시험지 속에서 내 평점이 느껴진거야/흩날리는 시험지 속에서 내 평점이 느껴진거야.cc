#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
int arr[100005];
int sum, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int left = 0;
	int right = sum;

	while (left <= right) {
		int tmp_sum = 0;
		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			tmp_sum += arr[i];
			if (tmp_sum >= mid) {
				cnt++;
				tmp_sum = 0;
			}
		}

		if (cnt >= k) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	
	cout << res;

	return 0;
}