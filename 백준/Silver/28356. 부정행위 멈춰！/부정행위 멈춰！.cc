#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 1 << "\n";
		cout << 1;
	}
	else if (n == 1) {
		cout << 2 << "\n";
		for (int i = 1; i <= m; i++) {
			cout << (i % 2 ? 1 : 2) << " ";
		}
	}
	else if (m == 1) {
		cout << 2 << "\n";
		for (int i = 1; i <= n; i++) {
			cout << (i % 2 ? 1 : 2) << "\n";
		}
	}
	else {
		cout << 4 << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i % 2 == 1 && j % 2 == 1) {
					cout << 1 << " ";
				}
				else if (i % 2 == 1 && j % 2 == 0) {
					cout << 2 << " ";
				}
				else if (i % 2 == 0 && j % 2 == 1) {
					cout << 3 << " ";
				}
				else {
					cout << 4 << " ";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}