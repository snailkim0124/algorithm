#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> v;
int mx, mxidx;
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);

		if (num == n) { // 최대 찾기
			mx = num;
			mxidx = i;
		}
	}

	while (v.size() > 1) {
		// 차이 최소 더하기
		if (mxidx - 1 >= 0 && mxidx + 1 < v.size()) {
			res += min(abs(v[mxidx] - v[mxidx - 1]), abs(v[mxidx] - v[mxidx + 1]));
		}
		else if (mxidx - 1 >= 0) res += abs(v[mxidx] - v[mxidx - 1]);
		else if (mxidx + 1 < v.size()) res += abs(v[mxidx] - v[mxidx + 1]);

		v.erase(v.begin() + mxidx); // 최대값 요소 제거
		mx--;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == mx) mxidx = i;
		}
	}

	cout << res;

	return 0;
}