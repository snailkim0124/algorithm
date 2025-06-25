#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for ( ; s.size() > 1 ; cnt++) {
		int multi = 1;
		for (auto it : s) {
			multi *= it - '0';
		}

		s = to_string(multi);
	}

	cout << cnt;

	return 0;
}