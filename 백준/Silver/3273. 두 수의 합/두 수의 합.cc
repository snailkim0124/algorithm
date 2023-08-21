#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, x, cnt;
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

	cin >> x;

	while (left < right) {
		if (a[left] + a[right] == x) {
			cnt++;
			left++;
			right--;
		}
		else if (a[left] + a[right] > x) right--;
		else left++;
	}
	cout << cnt;


	return 0;
}