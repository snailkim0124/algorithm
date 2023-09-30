#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;
int n, k;
int res;
int sum;
int arr[1000005];
int min_pos = 1000005, max_pos = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int g, x;
		cin >> g >> x;
		arr[x] = g;
		min_pos = min(min_pos, x);
		max_pos = max(max_pos, x);
	}

	k = 2 * k + 1; // 양동이 범위
	for (int i = min_pos; i <= max_pos; i++) {
		if (i >= k) {
			sum -= arr[i - k];
		}
		sum += arr[i];
		res = max(res, sum);
	}

	cout << res;
	return 0;
}