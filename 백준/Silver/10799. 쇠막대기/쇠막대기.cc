#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
string s;
stack<char> st;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(s[i]);
		else {
			if (i == 0) continue;
			if (s[i - 1] == '(') {
				st.pop();
				res += st.size();
			}
			else {
				st.pop();
				res++;
			}
		}
	}
	
	cout << res;
	return 0;
}