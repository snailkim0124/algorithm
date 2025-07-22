#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string s;
stack<int> st;
int check[200005];
int res, tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			if (!st.empty()) {
				check[st.top()] = 1;
				st.pop();
				check[i] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) {
			tmp++;
			res = max(res, tmp);
		}
		else tmp = 0;
	}

	cout << res;

	return 0;
}