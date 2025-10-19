#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, k;
map<pii, int> mp;
vector<pii> tmp;
int visited[4000005];
int parent[4000005];

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

	cin >> n >> m >> k;
	vector<int> v(m), v2(k);

	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < k; i++) {
		cin >> v2[i];
	}

	sort(all(v));
	for (int i = 0; i <= m; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < k; i++) {
		int idx = upper_bound(all(v), v2[i]) - v.begin();
		idx = findParent(idx);
		cout << v[idx] << "\n";
		
		unionParent(idx, idx + 1); // 쓴 인덱스 다음으로 연결
	}

	return 0;
}