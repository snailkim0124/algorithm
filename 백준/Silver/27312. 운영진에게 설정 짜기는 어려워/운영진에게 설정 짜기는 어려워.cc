#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int m, n, q;
int a[1005];
int visited[1005];
int ans[1005];

int query(int k, int i) {
	cout << "? " << k << " " << i << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		if (query(i, i) == 1) {
			ans[i] = 2;
		}
		else ans[i] = 1;
	}

	for (int i = m + 1; i <= n; i++) {
		ans[i] = 1;
	}

	// 답 출력하기
	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;


	return 0;
}