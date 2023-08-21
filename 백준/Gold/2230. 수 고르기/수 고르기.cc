#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int n, m, MIN = 2000000001, x, y;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int left = 0;
	int right = 0;
	while (left <= right && right < n) {
		int num = a[right] - a[left];

		if (num < m) {
			right++;
		}
		else if(num > m) {
			MIN = min(MIN, num);
			left++;
		}
		else {
			MIN = num;
			break;
			left++;
		}
	}

	cout << MIN;
	
	return 0;
}