#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int n, num=1;
int cnt;
int prime[4000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	prime[0] = 2;

	for (int i = 3; i <= n; i++) {
		bool flag = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			prime[num] = i;
			num++;
		}
	}

	int sum = prime[0];
	int left = 0;
	int right = 0;
	
	while (left <= right && right < num) {
		if (sum < n) {
			right++;
			sum += prime[right];
		}

		else if (sum == n) {
			cnt++;
			right++;
			sum += prime[right];
		}

		else {
			sum -= prime[left];
			left++;

			if (left > right) {
				right = left;
				sum = prime[right];
			}
		}
	}

	cout << cnt;
	return 0;
}