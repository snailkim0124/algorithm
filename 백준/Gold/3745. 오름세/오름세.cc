#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int main() {

	while (!cin.eof()) {
		a.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (a.empty() || a.back() < num) {
				a.push_back(num);
			}
			else {
				*lower_bound(a.begin(), a.end(), num) = num;
			}
		}

		if(!cin.eof()) cout << a.size() << "\n";
	}

	return 0;
}