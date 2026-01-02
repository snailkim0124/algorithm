#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int parent[100005];

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		unionParent(i, j);
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : " << findParent(i) << "\n";
	//}

	int cnt = 0;
	int now = -1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i == 0) {
			now = findParent(a);
		}
		else if (findParent(now) != findParent(a)) {
			now = findParent(a);
			cnt++;
		}
	}

	cout << cnt << "\n";

	
	return 0;
}