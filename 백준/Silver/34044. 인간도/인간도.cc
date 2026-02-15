#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	if (n == 1) {
		cout << -1 << "\n";
		exit(0);
	}

	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			cout << "3773";
		}
		cout << "\n";
	}
	else {
		if (n == 3) {
			cout << "131923\n";
		}
		else {
			for (int i = 0; i < n / 2 - 1; i++) {
				cout << "3773";
			}
			cout << "131923\n";

		}

		
	}

	

	return 0;
}