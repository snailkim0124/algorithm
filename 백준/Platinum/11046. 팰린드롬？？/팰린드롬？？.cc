#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> manacher(vector<int> s) {
	// 문자를 홀수 길이로 만들기
	vector<int> t;
	t.push_back(-1);

	for (int c : s) {
		t.push_back(c);
		t.push_back(-1);
	}

	int n = t.size();
	vector<int> p(n, 0);

	int c = 0; // 중심
	int r = 0;

	for (int i = 0; i < n; i++) {
		if (i < r) {
			p[i] = min(r - i, p[2 * c - i]);
		}

		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
			p[i]++;
		}

		// 최대 갱신
		if (i + p[i] > r) {
			c = i;
			r = i + p[i];
		}
	}

	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> ans = manacher(v);
	
	//for (int i = 0; i < ans.size(); i++) {
	//	cout << i << " : " << ans[i] << "\n";
	//}

	cin >> m;
	while (m--) {
		ll s, e;
		cin >> s >> e;
		ll len = e - s + 1;
		s--; e--;
		s = 2 * s + 1;
		e = 2 * e + 1;

		//for (int i = s; i <= e; i += 2) {
		//	cout << ans[i] << " ";
		//}
		//cout << "\n";

		// 최대 부분 펠린드롬 길이가 문자열 길이보다 길면됨
		ll mid = (s + e) / 2;
		if (ans[mid] >= len) {
			cout << 1 << "\n";
		}
		else cout << 0 << "\n";

	}


	return 0;
}