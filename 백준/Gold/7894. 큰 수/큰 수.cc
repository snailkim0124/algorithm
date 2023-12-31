#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		double ans = 0;
		cin >> m;

		while (m) {
			ans += log10(m);
			m--;
		}

		cout << (int)ans + 1 << "\n";
	}
	
	return 0;
}