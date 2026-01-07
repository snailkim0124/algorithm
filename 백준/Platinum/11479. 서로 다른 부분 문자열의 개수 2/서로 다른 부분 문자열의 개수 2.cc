#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<int> v, rnk;
int n, k;

bool cmp(int i, int j) {
	if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];

	int ri = (i + k < n ? rnk[i + k] : -1);
	int rj = (j + k < n ? rnk[j + k] : -1);

	return ri < rj;
}

vector<int> sa_func(string s) {
	n = s.size();
	vector<int> sa(n);
	rnk.resize(n, 0);

	for (int i = 0; i < n; i++) {
		sa[i] = i;
		rnk[i] = s[i];
	}

	vector<int> tmp(n);
	// 효율적으로 비교하기 위해 2배씩
	for (k = 1;; k <<= 1) {
		sort(all(sa), cmp);

		tmp[sa[0]] = 0;
		// 이전 suffix 배열 요소 비교
		for (int i = 1; i < n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}

		rnk = tmp;
		if (rnk[sa[n - 1]] == n - 1) break;
	}

	return sa;
}

vector<int> lcp_func(string s, vector<int> sa) {
	int n = s.size();
	vector<int> lcp(n), rank(n);
	
	// suffix 배열에서 몇번째?
	for (int i = 0; i < n; i++) {
		rank[sa[i]] = i;
	}

	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (rank[i] > 0) {
			// 바로 이전 suffix
			int j = sa[rank[i] - 1];
			while (i + idx < n && j + idx < n && s[i + idx] == s[j + idx]) {
				idx++;
			}

			lcp[rank[i]] = idx;

			if (idx > 0) idx--;
		}
	}

	return lcp;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	ll nn = s.size();

	vector<int> sa = sa_func(s);

	// 나올 수 있는 전체 경우의 수
	ll res = nn * (nn + 1) / 2;

	// 겹치는거 빼기
	ll cnt = 0;
	vector<int> lcp = lcp_func(s, sa);
	for (int i = 0; i < lcp.size(); i++) {
		cnt += lcp[i];
	}

	cout << res - cnt << "\n";

	return 0;
}