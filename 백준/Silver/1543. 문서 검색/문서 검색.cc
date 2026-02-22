#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, a);
	getline(cin, b);

	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		string tmp = a.substr(i, b.size());

		if (tmp == b) {
			cnt++;
			i += b.size() - 1;
		}
	}

	cout << cnt << "\n";

	return 0;
}