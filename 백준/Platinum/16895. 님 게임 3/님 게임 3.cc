#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int p[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x = 0;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		x ^= p[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if ((x ^ p[i]) < p[i]) cnt++;
	}

	// 이미 패배
	if (x == 0) {
		cout << 0 << "\n";
	}
	else {
		cout << cnt << "\n";
	}
	
	return 0;
}