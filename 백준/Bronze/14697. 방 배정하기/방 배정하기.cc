#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a, b, c, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> n;

	for (int i = 0; i <= 300; i++) {
		for (int j = 0; j <= 300; j++) {
			for (int k = 0; k <= 300; k++) {
				if (a * i + b * j + c * k == n) {
					cout << 1 << "\n";
					exit(0);
				}
			}
		}
	}
	
	cout << 0 << "\n";

	return 0;
}