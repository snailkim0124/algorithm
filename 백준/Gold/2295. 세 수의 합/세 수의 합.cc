#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
ll n, MIN = 5000000001, x, y, z;
ll a[5005];
ll res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int j = 0; j < n; j++) {
		ll ans = a[j];

		for (int i = 0; i < n-1; i++) {

			ll left = i;
			ll right = n - 1;

			while (left <= right) {
				if (a[left] + a[right] + a[i] == ans) {
					if (left != j && right != j && i != j) {
						res = ans;
						break;
					}
					else if (left == j) left++;
					else if (right == j) right--;
				}
				if (a[left] + a[right] + a[i] < ans) left++;
				else right--;
			}
		}
	}
	

	cout << res;


	return 0;
}