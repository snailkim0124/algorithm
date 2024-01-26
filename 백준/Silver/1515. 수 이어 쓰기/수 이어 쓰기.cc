#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

string s;
int cnt;
int ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	while (1) {
		string tmp = to_string(ans);
		for (int i = 0; i < tmp.size(); i++) {
			if (s[cnt] == tmp[i]) {
				cnt++;
			}
			if (cnt == s.size()) {
				cout << ans;
				exit(0);
			}
		}
		ans++;
	}

	return 0;
}