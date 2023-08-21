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
		if (a[left] + a[right] == 0) {
			x = a[right];
			y = a[left];
			cout << a[left] << " " << a[right];
			exit(0);
		}
		else if (a[left] + a[right] < 0) {
			if (abs(a[left] + a[right]) < MIN) {
				MIN = abs(a[left] + a[right]);
				x = a[right];
				y = a[left];
			}
			left++;
		}
		else {
			if (abs(a[left] + a[right]) < MIN) {
				MIN = abs(a[left] + a[right]);
				x = a[right];
				y = a[left];
			}
			right--;
		}
	}
	cout << y << " " << x;


	return 0;
}