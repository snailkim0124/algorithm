#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k;
int c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	cin >> c;
	while (c--) {
		int m, n;
		cin >> m >> n;
		if (m == n) {
			cout << 1 << "\n";
			continue;
		}

		int tmp = k - max(m, n);
		
		if (m > n) {
			if (abs(m - n) - tmp <= 2) {
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
			continue;
		}
		
		if (abs(m - n) - tmp <= 1) {
			cout << 1 << "\n";
			continue;
		}

		cout << 0 << "\n";
	}
	
	

	return 0;
}