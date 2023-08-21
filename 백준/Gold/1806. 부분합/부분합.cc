#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, s, MIN = 2000000001;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left = 0;
	int right = 0;
	int sum = a[0];

	while (left <= right && right < n) {
		if (sum >= s) {
			if (right - left + 1 < MIN) {
				MIN = right - left +1;
			}
			sum -= a[left];
			left++;
		}
		else {
			right++;
			sum += a[right];
		}
	}
	if (MIN == 2000000001) {
		cout << "0";
	}
	else {
		cout << MIN;
	}

	return 0;
}