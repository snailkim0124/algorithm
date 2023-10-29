#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k;
vector<ll> mintree;
const ll INF = 1e18;

ll treemin(ll s, ll e) {
	ll res = INF;

	while (s <= e) {
		if (s % 2 == 1) {
			res = min(res, mintree[s]);
			s++;
		}
		if (e % 2 == 0) {
			res = min(res, mintree[e]);
			e--;
		}
		s /= 2;
		e /= 2;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	ll treeheight = 0;
	ll length = n;

	while (length != 0) {
		length /= 2;
		treeheight++;
	}

	ll treesize = ll(pow(2, treeheight + 1));
	ll leftnodestartindex = treesize / 2 - 1;
	mintree.resize(treesize + 1);
	fill(mintree.begin(), mintree.end(), INF);

	for (int i = leftnodestartindex + 1; i <= leftnodestartindex + n; i++) {
		ll num;
		cin >> num;
		mintree[i] = num;
	}

	ll i = treesize - 1;
	while (i != 1) { // mintree 만들기
		mintree[i / 2] = min(mintree[i / 2], mintree[i]);
		i--;
	}

	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a += leftnodestartindex;
		b += leftnodestartindex;
		cout << treemin(a, b) << "\n";
	}

	return 0;
}