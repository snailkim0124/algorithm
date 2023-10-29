#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k;
vector<ll> tree;

ll sum(ll s, ll e) {
	ll res = 0;

	while (s <= e) {
		if (s % 2 == 1) {
			res += tree[s];
			s++;
		}
		if (e % 2 == 0) {
			res += tree[e];
			e--;
		}
		s /= 2;
		e /= 2;
	}

	return res;
}

void change(ll idx, ll val) {
	ll diff = val - tree[idx];

	while (idx > 0) {
		tree[idx] += diff;
		idx /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	ll treeheight = 0;
	ll length = n;

	while (length != 0) {
		length /= 2;
		treeheight++;
	}

	ll treesize = ll(pow(2, treeheight + 1));
	ll leftnodestartindex = treesize / 2 - 1;
	tree.resize(treesize + 1);

	for (int i = leftnodestartindex + 1; i <= leftnodestartindex + n; i++) {
		cin >> tree[i];
	}

	ll i = treesize - 1;
	while (i != 1) { // tree 만들기
		tree[i / 2] += tree[i];
		i--;
	}

	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;

		if (a == 1) { // b -> c로 바꾸기
			change(leftnodestartindex + b, c);
		}
		else if (a == 2) { // 합 출력
			b += leftnodestartindex;
			c += leftnodestartindex;
			cout << sum(b, c) << "\n";
		}
	}

	return 0;
}