#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		stack<int> st;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') st.push(1);
			if (s[j] == ')') {
				if (st.size()) st.pop();
				else flag = false;
			}
		}
		if (flag == true) {
			if (st.size() == 0) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
	
	return 0;
}