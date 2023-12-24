#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int k;

bool ispalinedrome(string a, string b) {
	string tmp;
	tmp = a + b;
	reverse(tmp.begin(), tmp.end());

	return (tmp == a+b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		bool flag = false;
		string ans;
		cin >> k;
		vector<string> v(k);
		for (int i = 0; i < k; i++) {
			cin >> v[i];
			//cout << ispalinedrome(v[i]) << "\n";
		}

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i == j) continue;
				if (ispalinedrome(v[i], v[j])) {
					flag = true;
					ans = v[i] + v[j];
					break;
				}
			}
			if (flag) break;
		}
		
		if (flag) cout << ans << "\n";
		else cout << 0 << "\n";

	}
	

	return 0;
}