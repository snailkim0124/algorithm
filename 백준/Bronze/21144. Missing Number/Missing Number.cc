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
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	int idx = 0;

	for (int i = 1; i <= n; i++) {
		string tmp = to_string(i);
		if (s.substr(idx, tmp.size()) != tmp) {
			cout << i << "\n";
			break;
		}
		else idx += tmp.size();
	}

	
	return 0;
}