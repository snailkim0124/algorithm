#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;
set<string> st;
string s, word;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		string tmp = "";
		for (int j = i; j < s.size(); j++) {
			tmp += s[j];
			st.insert(tmp);
		}
	}
	cout << st.size();
}