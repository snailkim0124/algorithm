#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int a[20005], tmp;

int check(int n) {
	int res = n;
	while (n > 0) {
		res = res + n % 10;
		n = n / 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i < 10001; i++) {
		tmp = check(i);
		if (tmp < 10001) {
			a[tmp] = 1;
		}
	}

	for (int i = 1; i < 10001; i++) {
		if (a[i] != 1) {
			cout << i << "\n";
		}
	}


	return 0;
}