#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n;
		int cnt = 0;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			if (i * i <= n) cnt++;
		}

		cout << cnt << "\n";
	}
	

	return 0;
}