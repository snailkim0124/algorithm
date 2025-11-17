#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	cin.ignore();

	while (t--) {
		string s;
		cin >> s;
		
		if (s.size() % 2 == 1) s += s;

		string a = "", b = "";

		for (int i = 0; i < s.size(); i += 2) {
			a += s[i];
		}

		for (int i = 1; i < s.size(); i += 2) {
			b += s[i];
		}

		cout << a << "\n" << b << "\n";
	}

	return 0;
}