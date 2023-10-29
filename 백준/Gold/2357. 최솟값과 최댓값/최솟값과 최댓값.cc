#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k;
vector<ll> mintree;
vector<ll> maxtree;
const ll INF = 1e18;

ll treemax(ll s, ll e) {
	ll res = -1;
	while (s <= e) {
		if (s % 2 == 1) {
			res = max(res, maxtree[s]);
			s++;
		}
		if (e % 2 == 0) {
			res = max(res, maxtree[e]);
			e--;
		}
		s /= 2;
		e /= 2;
	}

	return res;
}

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
	maxtree.resize(treesize + 1);
	fill(maxtree.begin(), maxtree.end(), -1);

	for (int i = leftnodestartindex + 1; i <= leftnodestartindex + n; i++) {
		ll num;
		cin >> num;
		mintree[i] = num;
		maxtree[i] = num;
	}

	ll i = treesize - 1;
	while (i != 1) { // mintree 만들기
		mintree[i / 2] = min(mintree[i / 2], mintree[i]);
		i--;
	}

	i = treesize - 1;
	while (i != 1) { // maxtree 만들기
		maxtree[i / 2] = max(maxtree[i / 2], maxtree[i]);
		i--;
	}

	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a += leftnodestartindex;
		b += leftnodestartindex;
		cout << treemin(a, b) << " " << treemax(a, b) << "\n";
	}

	return 0;
}