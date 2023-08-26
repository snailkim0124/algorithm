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

	for (int i = 2; i * i < 1000001; i++) {
		if (check[i] == 0) {
			for (int j = i + i; j < 1000001; j += i) {
				check[j] = 1;
			}
		}
	}

	while(1) {
		cin >> n;

		if (n == 0) break;

		bool flag = false;
		for (int j = 2; j <= n/2; j++) {
			if (check[j] == 0 && check[n - j] == 0) {
				cout << n << " = " << j << " + " << n - j;
				flag = true;
				break;
			}
		}
		if (flag == false) {
			cout << "Goldbach's conjecture is wrong.";
		}
		cout << "\n";
	}
	return 0;
}