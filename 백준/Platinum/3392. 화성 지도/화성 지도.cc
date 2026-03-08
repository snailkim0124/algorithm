#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct LINE {
	pll p1, p2;
	ll s;
};

const ll MAX = 30000;
ll n;
vector<LINE> v;
vector<ll> tree_cnt, tree_sum;

bool cmp(LINE A, LINE B) {
	return A.p1.first < B.p1.first;
}

void update(int node, int s, int e, int l, int r, int val) {
	if (l > e || r < s) return;
	
	if (l <= s && e <= r) {
		tree_cnt[node] += val;
	}
	else {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, l, r, val);
		update(node * 2 + 1, mid + 1, e, l, r, val);
	}


	if (tree_cnt[node]) {
		tree_sum[node] = e + 1 - s;
	}
	else {
		if (s == e) tree_sum[node] = 0;
		else {
			tree_sum[node] = tree_sum[node * 2] + tree_sum[node * 2 + 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ { x1, y1 }, { x1, y2 }, 1 }); // 세로선
		v.push_back({ { x2, y1 }, { x2, y2 }, -1 });
	}

	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	tree_cnt.assign(tree_size, 0);
	tree_sum.assign(tree_size, 0);

	sort(all(v), cmp);

	ll res = 0;
	for (int i = 0; i < v.size(); i++) {
		LINE now = v[i];

		if (i > 0) {
			ll dx = now.p1.first - v[i - 1].p1.first;
			ll dy = tree_sum[1]; // 세로 색칠한 길이
			res += dx * dy;
		}

		// 세로 색칠
		update(1, 0, MAX, now.p1.second, now.p2.second - 1, now.s);
	}

	cout << res << "\n";

	return 0;
}