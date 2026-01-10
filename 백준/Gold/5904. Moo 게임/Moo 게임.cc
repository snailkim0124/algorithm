#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void dfs(int idx, int k, int sz) {
	int sk1 = (sz - k - 3) / 2; // s(k-1) 길이

	// 왼쪽
	if (idx <= sk1) {
		dfs(idx, k - 1, sk1);
	}
	// 오른쪽
	else if (idx > k + 3 + sk1) {
		dfs(idx - (k + 3 + sk1), k - 1, sk1);
	}
	else {
		// 정답 범위
		if (idx - sk1 == 1) {
			cout << "m\n";
		}
		else {
			cout << "o\n";
		}
		return;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int sz = 3;
	int k = 0;
	while (sz < n) {
		k++;
		sz = sz * 2 + k + 3;
	}

	dfs(n, k, sz);
	

	return 0;
}