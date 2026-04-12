#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, x;
int t[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	if (x > t[0]) {
		cout << 1 << "\n";
		exit(0);
	}

	int idx = 1;
	while (1) {
		if (x + 1 > t[idx]) {
			cout << idx + 1 << "\n";
			break;
		}
		x++;
		idx = (idx + 1) % n;
	}
	
	return 0;
}