#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			st.push(s[i] - '0');
		}
		else {
			int a, b;
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			if (s[i] == '+') {
				st.push(b + a);
			}
			else if (s[i] == '-') {
				st.push(b - a);
			}
			else if (s[i] == '*') {
				st.push(b * a);
			}
			else if (s[i] == '/') {
				st.push(b / a);
			}
		}
	}

	cout << st.top();

	return 0;
}