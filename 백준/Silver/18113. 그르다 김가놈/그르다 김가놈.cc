#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k, m;
int arr[1000005];
int res = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= 2 * k) arr[i] -= 2 * k;
		else if (arr[i] >= k) arr[i] -= k;
		else {
			arr[i] = 0;
		}
	}

	int left = 1;
	int right = 1e9;

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += arr[i] / mid;
		}

		if (sum >= m) {
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