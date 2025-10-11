#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int m, n;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	while (1) {
		if (m < n) {
			if (m % n < 10) {
				ans += (m % n) + '0';
			}
			else {
				ans += (m % n - 10) + 'A';
			}
			break;
		}

		if (m % n < 10) {
			ans += (m % n) + '0';
		}
		else {
			ans += (m % n - 10) + 'A';
		}

		m /= n;
	}
	reverse(all(ans));

	cout << ans << "\n";


	return 0;
}
