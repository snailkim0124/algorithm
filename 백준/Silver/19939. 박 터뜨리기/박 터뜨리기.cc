#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k; // 공 개수, 팀 수

	if (n <= k) {
		cout << -1;
		exit(0);
	}
	if (k == 2) {
		if (n % 2 == 0) {
			cout << 2;
		}
		else {
			cout << 1;
		}
		exit(0);
	}

	sum += k * (k + 1) / 2;
	if (sum > n) {
		cout << -1;
	}
	else if ((n - sum) % k == 0) {
		cout << k - 1;
	}
	else {
		cout << k;
	}

	return 0;
}