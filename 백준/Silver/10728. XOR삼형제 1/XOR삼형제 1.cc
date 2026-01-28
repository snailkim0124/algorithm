#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

// 최상위비트 찾기
int msb(int num) {
	int res = 1;
	while ((res << 1) <= num) {
		res <<= 1;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << "\n" << 1 << "\n";
		return;
	}

	vector<int> ans;

	int m = msb(n);

	int s = m / 2;
	int e = min(n, s + m - 1);

	for (int i = s; i <= e; i++) {
		ans.push_back(i);
	}


	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//for (int i = 5; i <= 13; i++) {
	//	for (int j = 5; j <= 13; j++) {
	//		cout << i << " : " << j << " : " << (i ^ j) << "\n";
	//	}
	//}

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	

	return 0;
}