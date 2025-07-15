#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
stack<char> st;
int res, temp = 1;
bool toggle;
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (auto it : s) {
		if (st.empty() || it == '(' || it == '[') {
			st.push(it);
			toggle = true;
			if (it == '(') temp *= 2;
			else temp *= 3;
		}
		else if (it == ')') {
			if (st.top() == '(') {
				st.pop();
				if (toggle) res += temp;
				toggle = false;
				temp /= 2;
			}
			else {
				flag = true;
				break;
			}
		}
		else if (it == ']') {
			if (st.top() == '[') {
				st.pop();
				if (toggle) res += temp;
				toggle = false;
				temp /= 3;
			}
			else {
				flag = true;
				break;
			}
		}
	}

	if (flag || !st.empty()) cout << 0;
	else cout << res;

	return 0;
}