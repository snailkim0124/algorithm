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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n-2; i++) {
		ll left = i + 1;
		ll right = n - 1;

		while (left < right) {
			if (abs(a[left] + a[right] + a[i]) < MIN)			{
				MIN = abs(a[left] + a[right] + a[i]);
				x = a[left];
				y = a[right];
				z = a[i];
			}
			if (a[left] + a[right] + a[i] < 0) left++;
			else right--;
		}
	}
	
	cout << z << " " << x << " " << y;


	return 0;
}