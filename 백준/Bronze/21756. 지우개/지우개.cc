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
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	while (v.size() > 1) {
		vector<int> tmp;

		for (int i = 1; i < v.size(); i += 2) {
			tmp.push_back(v[i]);
		}

		v = tmp;
	}

	cout << v[0] << "\n";
	
	return 0;
}