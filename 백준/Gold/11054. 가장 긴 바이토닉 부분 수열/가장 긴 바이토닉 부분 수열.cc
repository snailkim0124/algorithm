#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int n;
int a[1004];
int dp1[1004];
int dp2[1004];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	for (int i = n-1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n-1; j > i; j--) {
			if (a[i] > a[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cnt = max(cnt, dp1[i] + dp2[i]);
	}
	cnt--;

	cout << cnt;
	return 0;
}