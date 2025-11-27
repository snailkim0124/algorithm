#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s, t;
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> t;
	n = s.size();
	m = t.size();

	string tmps = "";
	for (int i = 0; i < m; i++) {
		tmps += s;
	}

	string tmpt = "";
	for (int i = 0; i < n; i++) {
		tmpt += t;
	}

	cout << (tmps == tmpt ? 1 : 0) << "\n";

	
	
	return 0;
}