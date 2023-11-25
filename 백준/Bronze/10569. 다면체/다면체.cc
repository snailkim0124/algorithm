#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e; // 꼭짓점, 모서리
		cout << 2 - v + e << "\n";
	}
	
	return 0;
}