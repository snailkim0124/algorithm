#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int t, n;
int check[10005];
int a[10005];
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 2; i * i < 10001; i++) {
		if (check[i] == 0) {
			for (int j = i + i; j < 10001; j += i) {
				check[j] = 1;
			}
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++) {
		int res = 0;
		cin >> n;

		for (int j = n/2; j > 0; j--) {
			if (check[j] == 0 && check[n - j] == 0) {
				cout << j << " " << n - j;
				break;
			}
		}
		cout << "\n";
	}
	return 0;
}