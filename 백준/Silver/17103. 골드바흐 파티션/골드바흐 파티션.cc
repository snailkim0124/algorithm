#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int t, n;
int check[1000005];
int a[1000005];
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 2; i < 1000001; i++) {
		if (check[i] == 0) {
			a[cnt] = i;
			cnt++;
			for (int j = i + i; j < 1000001; j += i) {
				check[j] = 1;
			}
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++) {
		int res = 0;
		cin >> n;

		for (int j = 0; j < cnt; j++) {
			if (a[j] <= n - a[j] && check[n - a[j]] == 0) res++;
		}
		cout << res << "\n";
	}
	return 0;
}