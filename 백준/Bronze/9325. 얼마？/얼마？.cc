#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> s;
		cin >> n;
		while (n--) {
			int q, p;
			cin >> q >> p;
			s += q * p;
		}

		cout << s << "\n";
	}
	
	return 0;
}