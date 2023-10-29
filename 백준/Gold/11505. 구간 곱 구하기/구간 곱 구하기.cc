#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k;
vector<ll> tree;
const ll mod = 1000000007;

ll multi(ll s, ll e) {
	ll res = 1;

	while (s <= e) {
		if (s % 2 == 1) {
			res = res * tree[s] % mod;
			s++;
		}
		if (e % 2 == 0) {
			res = res * tree[e] % mod;
			e--;
		}
		s /= 2;
		e /= 2;
	}

	return res;
}

void change(ll idx, ll val) {
	tree[idx] = val;

	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] % mod * tree[idx * 2 + 1] % mod;
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
	fill(tree.begin(), tree.end(), 1);

	for (int i = leftnodestartindex + 1; i <= leftnodestartindex + n; i++) {
		cin >> tree[i];
	}

	ll i = treesize - 1;
	while (i != 1) { // tree 만들기
		tree[i / 2] = tree[i / 2] * tree[i] % mod;
		i--;
	}

	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;

		if (a == 1) { // b -> c로 바꾸기
			change(leftnodestartindex + b, c);
		}
		else if (a == 2) { // 곱 출력
			b += leftnodestartindex;
			c += leftnodestartindex;
			cout << multi(b, c) << "\n";
		}
	}

	return 0;
}