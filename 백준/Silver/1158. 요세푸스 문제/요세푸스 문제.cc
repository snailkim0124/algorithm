#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	int idx = 0;
	cout << "<";
	while (!v.empty()) {
		idx = (idx + k - 1) % v.size();
		if(v.size() == 1) cout << v[idx];
		else cout << v[idx] << ", ";
		v.erase(v.begin() + idx);
	}
	cout << ">";

	return 0;
}