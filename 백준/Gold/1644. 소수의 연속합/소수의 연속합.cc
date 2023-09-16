#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int n, num;
int cnt, sum;
int prime[4000005]; // 소수 인지 아닌지
int a[4000005]; // 소수 집합

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (prime[i]) continue;
		for (int j = 2 * i; j <= n; j += i) {
			prime[j] = 1; // 에라토스테네스의 체
		}
	}

	for (int i = 2; i <= n; i++) { 
		if (!prime[i]) { // 소수이면
			a[num] = i;
			num++;
		}
	}

	int left = 0;
	int right = 0;
	while (1) {
		if (sum >= n) {
			sum -= a[left];
			left++;
		}
		else if (right == num) break;
		else {
			sum += a[right];
			right++;
		}

		if (sum == n) cnt++;
	}

	cout << cnt;
	return 0;
}