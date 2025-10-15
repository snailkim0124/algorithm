#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		double n;
		cin >> n;
		if (n == 0) break;

		double sum = 0;
		for (int i = 2; ; i++) {
			sum += 1.0 / i;

			if (sum >= n) {
				cout << i - 1;
				break;
			}
		}

		cout << " card(s)\n";
	}
	

	return 0;
}
