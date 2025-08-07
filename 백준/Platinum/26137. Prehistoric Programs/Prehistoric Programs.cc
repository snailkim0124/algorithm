#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct TABLETS {
	int idx, left, right;
}TABLETS;

int n;
vector<TABLETS> v, l, r;
vector<int> res;
int cnt; // 예외 케이스

bool cmpl(TABLETS& a, TABLETS& b) {
	return a.left < b.left;
}

bool cmpr(TABLETS& a, TABLETS& b) {
	return a.right > b.right;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		stack<char> st;
		int left = 0, right = 0;
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			if (st.empty()) {
				st.push(s[j]);
				continue;
			}
			else if (st.top() != s[j]) {
				if (st.top() == '(') {
					st.pop();
					continue;
				}
			}
			st.push(s[j]);
		}

		while (!st.empty()) {
			if (st.top() == '(') right++;
			else left++;
			st.pop();
		}
		
		if (right > left) l.push_back({ i, left, right });
		else r.push_back({ i, left, right });
	}

	// 따로 정렬하기
	sort(l.begin(), l.end(), cmpl);
	sort(r.begin(), r.end(), cmpr);

	for (auto it : l) v.push_back(it);
	for (auto it : r) v.push_back(it);

	for (auto it : v) {
		res.push_back(it.idx);
		cnt -= it.left;
		if (cnt < 0) {
			cout << "impossible\n";
			exit(0);
		}
		cnt += it.right;
	}

	// 딱 떨어지면
	if (cnt == 0) {
		for (auto it : res) {
			cout << it << "\n";
		}
	}
	else {
		cout << "impossible\n";
	}

	return 0;
}