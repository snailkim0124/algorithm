#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
stack<char> st;
bool flag;

void print_all() {
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			print_all();
			flag = true;
			cout << s[i];
		}
		else if (s[i] == '>') {
			flag = false;
			cout << s[i];
		}
		else if (flag) cout << s[i];
		else if (s[i] == ' ') {
			print_all();
			cout << s[i];
		}
		else st.push(s[i]); // 누적

	}
	print_all();
	
	return 0;
}