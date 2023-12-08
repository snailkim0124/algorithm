#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int alpha1[27];
int alpha2[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(alpha1, 0, sizeof(alpha1));
		memset(alpha2, 0, sizeof(alpha2));
		bool check = false;
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++) {
			alpha1[a[i] - 'a']++;
		}

		for (int i = 0; i < b.size(); i++) {
			alpha2[b[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (alpha1[i] != alpha2[i]) {
				check = true;
				break;
			}
		}

		if (!check) cout << "Possible\n";
		else cout << "Impossible\n";

	}

	return 0;
}