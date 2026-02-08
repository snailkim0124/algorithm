#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int dir;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		int t;
		cin >> t;
		if (t == 1) dir = (dir + 1) % 4;
		else if (t == 2) dir = (dir + 2) % 4;
		else if (t == 3) dir = (dir + 3) % 4;
	}
	
	if (dir == 0) cout << "N\n";
	else if (dir == 1) cout << "E\n";
	else if (dir == 2) cout << "S\n";
	else if (dir == 3) cout << "W\n";

	return 0;
}