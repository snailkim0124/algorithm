#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
ll n, m, MIN = 5000000001, x, y, z;
ll a[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n - 2; i++) {
		ll left = i + 1;
		ll right = n - 1;

		while (left < right) {
			ll sum = a[left] + a[right] + a[i];
			if (a[left] == m || a[right] == m || a[i] == m || a[left] + a[right] == m || a[left] + a[i] == m || a[right] + a[i] == m) {
				cout << "1";
				exit(0);
			}

			if (sum == m) {
				cout << "1";
				exit(0);
			}
			else if (sum < m) left++;
			else right--;
		}
	}

	cout << "0";


	return 0;
}