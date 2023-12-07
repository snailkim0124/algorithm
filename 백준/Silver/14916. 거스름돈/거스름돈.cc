#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	if (n == 1 || n == 3) {
		cout << -1;
		exit(0);
	}

	if (n % 5 == 0) {
		cout << n / 5;
	}
	else {
		while (n > 0) {
			n -= 2;
			cnt++;
			if (n % 5 == 0) {
				cout << cnt + n / 5;
				break;
			}
		}
		if (n < 0) {
			cout << -1;
		}
	}

	return 0;
}