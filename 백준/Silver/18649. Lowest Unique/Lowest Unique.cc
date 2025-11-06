#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> m;
	while (m--) {
		for (int i = 1; i <= k; i++) {
			cout << i << " ";
		}
		cout << endl;

		for (int i = 0; i < n - k; i++) {
			int num;
			cin >> num;
		}
	}
	

	return 0;
}