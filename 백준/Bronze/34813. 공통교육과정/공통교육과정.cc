#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	if (s[0] == 'F') {
		cout << "Foundation";
	}
	else if (s[0] == 'C') {
		cout << "Claves";
	}
	else if (s[0] == 'V') {
		cout << "Veritas";
	}
	else if (s[0] == 'E') {
		cout << "Exploration";
	}

	
	return 0;
}