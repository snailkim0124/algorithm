#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
string s;
stack<int> st; // 인덱스 담기
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		bool check = false;
		if (s[i] == 's') {
			st.push(0);
			check = true;
		}
		else if (s[i] == 'k') {
			if (!st.empty() && st.top() == 0) {
				st.top() += 1;
				check = true;
			}
		}
		else if (s[i] == 'e') {
			if (!st.empty() && (st.top() == 1 || st.top() == 2)) {
				st.top() += 1;
				check = true;
			}
		}
		else if (s[i] == 'p') {
			if (!st.empty() && st.top() == 3) {
				st.top() += 1;
				check = true;
			}
		}

		if (!check) {
			// 초기화
			while (!st.empty()) {
				st.pop();
			}
			continue;
		}

		while (!st.empty()) {
			if (st.top() != 4) break;
			cnt++;
			st.pop();

			if (!st.empty()) st.top() += 1;
		}
	}

	cout << cnt;

	return 0;
}