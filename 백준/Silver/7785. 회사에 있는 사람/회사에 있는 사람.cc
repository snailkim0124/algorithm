#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
set<string> st;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string member = "";
		string log = "";
		cin >> member >> log;
		if (log == "enter") {
			st.insert(member);
		}
		else {
			st.erase(member);
		}
	}

	for (auto it = st.rbegin(); it != st.rend(); it++) {
		cout << *it << "\n";
	}
}