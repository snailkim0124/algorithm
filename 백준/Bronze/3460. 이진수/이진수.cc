#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int idx = 0;
		while (n != 0) {
			if (n & 1) {
				cout << idx << " ";
			}
			n >>= 1;
			idx++;
		}
		cout << "\n";
	}
	
	
	return 0;
}