#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int tt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tt;
	while (tt--) {
		double n;
		cin >> n;

		double sum = 0;
		for (int i = 0; i < 6; i++) {
			int num;
			cin >> num;
			sum += num;
		}

		if (n < sum) {
			cout << 1 << "\n";
		}
		else {
			cout << (int)((0.5) * log2((int)(n / sum))) + 2 << "\n";
		}
	}
	
	
	return 0;
}