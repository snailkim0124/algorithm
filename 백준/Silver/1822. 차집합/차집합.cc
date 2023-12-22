#include <bits/stdc++.h>

using namespace std;

int a, b;
set<int> s;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int anum;
		cin >> anum;
		s.insert(anum);
	}

	for (int i = 0; i < b; i++) {
		int bnum;
		cin >> bnum;

		if (s.find(bnum) != s.end()) {
			s.erase(bnum);
		}
	}

	cout << s.size() << "\n";
	if (s.size()) {
		for (auto it : s) {
			cout << it << " ";
		}
	}

	return 0;
}