#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;

		cout << "Distances: ";
		for (int i = 0; i < a.size(); i++) {
			if (a[i] <= b[i]) {
				cout << b[i] - a[i] << " ";
			}
			else {
				cout << b[i] - a[i] + 26 << " ";
			}
		}
		cout << "\n";
	}

	
	return 0;
}