#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int m, seed, x1, x2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> seed >> x1 >> x2;
	for (int a = 0; a < m; a++) {
		for (int c = 0; c < m; c++) {
			bool flag1 = (x1 == (a * seed + c) % m);
			bool flag2 = (x2 == (a * x1 + c) % m);

			if (flag1 && flag2) {
				cout << a << " " << c;
				exit(0);
			}
		}
	}

	
	return 0;
}