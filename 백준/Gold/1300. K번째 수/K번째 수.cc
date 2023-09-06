#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
int n, k;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> k;
	int left = 1;
	int right = k;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			cnt += min(mid/i, n);
		}

		if (cnt < k) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			ans = mid;
		}
	}

	cout << ans;
	return 0;
}