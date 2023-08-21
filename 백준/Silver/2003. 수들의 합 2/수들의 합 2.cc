#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, m;
int a[10005];
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = a[0];
	int left = 0;
	int right = 0;

	while (left <= right && right < n) {
		if (sum < m) {
			right++;
			sum += a[right];
		}
		
		else if(sum == m) {
			cnt++;

			right++;
			sum += a[right];


		}
		else {
			sum -= a[left];
			left++;

			if (left > right) {
				right = left;
				sum = a[right];
			}
		}
	}

	cout << cnt;
	
	return 0;
}