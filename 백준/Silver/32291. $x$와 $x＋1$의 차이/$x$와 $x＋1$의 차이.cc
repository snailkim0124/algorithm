#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll x;
set<ll> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x;
	x++;
	s.insert(1);
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			s.insert(i);
			s.insert(x / i);
		}
	}

	for (auto it : s) {
		cout << it << " ";
	}
	cout << "\n";
	

	return 0;
}