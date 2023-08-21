#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, MIN = 2000000001, x, y;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int left = 0;
	int right = n - 1;

	while (left < right) {
		int sum = a[left] + a[right];

		if (MIN > abs(sum)) {
			MIN = abs(sum);
			x = a[left];
			y = a[right];

			if (sum == 0) break;
		}

		if (sum < 0) left++;
		else right--;
	}
	cout << x << " " << y;


	return 0;
}