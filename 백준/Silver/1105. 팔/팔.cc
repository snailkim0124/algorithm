#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string l, r;
ll cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> r;
	
	if (l.size() != r.size()) {
		cout << 0;
		exit(0);
	}

	for (int i = 0; i < l.size(); i++) {
		if (l[i] == r[i] && l[i] == '8') {
			cnt++;
		}
		else if (l[i] != r[i] && (l[i] != '8' || r[i] != '8')) {
			break;
		}
	}

	cout << cnt;

	return 0;
}