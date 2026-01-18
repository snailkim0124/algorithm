#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll m, n;
ll ans[705][705], diff[1405];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = 1;
		}
	}

	while (n--) {
		ll zero, one, two;
		cin >> zero >> one >> two;
		// 1씩 증가
		diff[zero]++;
		// 2씩 증가
		diff[zero + one]++;
	}

	for (int i = 1; i < 2 * m - 1; i++) {
		diff[i] += diff[i - 1];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// 왼쪽 열
			if (j == 0) {
				ans[i][j] += diff[m - 1 - i];
			}
			else {
				ans[i][j] += diff[m - 1 + j];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}