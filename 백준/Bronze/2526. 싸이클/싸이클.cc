#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, p, tmp;
int ans;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> p;
	v.push_back(n);
	tmp = n;

	while (1) {
		if (find(v.begin(), v.end(), (tmp * n) % p) == v.end()) {
			v.push_back((tmp * n) % p);
			tmp = (tmp * n) % p;
		}
		else {
			ans = (tmp * n) % p;
			break;
		}
	}

	cout << v.size() - (find(v.begin(), v.end(), ans) - v.begin());
	
	return 0;
}
