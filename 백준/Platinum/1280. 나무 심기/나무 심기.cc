#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll MAX = 200005;
vector<pll> tree;
const ll mod = 1000000007;

void update(int node, int s, int e, int idx, ll val) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node].first++; // 개수 카운트
		tree[node].second += val; // 숫자
		return;
	}

	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, val);
	update(node * 2 + 1, mid + 1, e, idx, val);

	tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
	tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
}

pll query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return {0 ,0};
	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	pll left = query(node * 2, s, mid, l, r);
	pll right = query(node * 2 + 1, mid + 1, e, l, r);

	return { left.first + right.first , left.second + right.second };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	tree.resize(MAX * 4);

	ll now;
	cin >> now;

	ll res = 1;

	update(1, 0, MAX, now, now);
	for (int i = 0; i < n - 1; i++) {
		cin >> now;

		pll left = query(1, 0, MAX, 0, now - 1);
		pll right = query(1, 0, MAX, now + 1, MAX);

		/*cout << "left : \n";
		cout << left.first << " : " << left.second << "\n";

		cout << "right : \n";
		cout << right.first << " : " << right.second << "\n";*/

		ll ltmp = ((left.first * now - left.second) % mod + mod) % mod;
		ll rtmp = ((right.second - right.first * now) % mod + mod) % mod;

		res = (res % mod) * ((ltmp + rtmp) % mod);
		res %= mod;

		//for (int j = 0; j < n * 4; j++) {
		//	cout << j << " : " << tree[j].first << " : " << tree[j].second << "\n";
		//}

		update(1, 0, MAX, now, now);
	}


	
	cout << res << "\n";

	return 0;
}