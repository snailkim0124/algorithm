#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int cnt = 0;
		string s;
		getline(cin, s);
		if (s == "#") break;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] =='A' || s[i] =='E' || s[i] =='I' || s[i] =='O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
	
	return 0;
}