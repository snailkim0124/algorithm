#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1'000'000'007;
string s;
ll a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a') {
			a = (a * 2 + 1) % mod;
		}
		else if (s[i] == 'b') {
			b = (b * 2 + a) % mod;
		}
		else if (s[i] == 'c') {
			c = (c * 2 + b) % mod;
		}
	}

	cout << c << "\n";
	
	return 0;
}