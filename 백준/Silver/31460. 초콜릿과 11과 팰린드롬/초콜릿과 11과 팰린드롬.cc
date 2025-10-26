#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}

		if (n % 2 == 0) {
			for (int i = 0; i < n; i++) {
				cout << 1;
			}
			cout << "\n";
		}
		else {
			if ((n - 3) % 4 == 0) {
				for (int i = 0; i < (n - 3) / 2; i++) {
					cout << 1;
				}
				cout << 121;
				for (int i = 0; i < (n - 3) / 2; i++) {
					cout << 1;
				}

				cout << "\n";
			}
			else if ((n - 5) % 4 == 0) {
				for (int i = 0; i < (n - 5) / 2; i++) {
					cout << 1;
				}
				cout << 14641;
				for (int i = 0; i < (n - 5) / 2; i++) {
					cout << 1;
				}
				cout << "\n";
			}
		}
	}
	
	return 0;
}