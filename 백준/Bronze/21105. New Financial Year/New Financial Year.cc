#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(5);

	cin >> n;
	while (n--) {
		double p, c;
		cin >> p >> c;
		cout << 100 * p / (c + 100) << "\n";
	}

	return 0;
}