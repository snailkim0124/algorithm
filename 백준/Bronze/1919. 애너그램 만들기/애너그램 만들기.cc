#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b;
int alpha1[27];
int alpha2[27];
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a;
	cin >> b;

	for (int i = 0; i < a.size(); i++) {
		alpha1[a[i] - 'a']++;
	}
	for (int i = 0; i < b.size(); i++) {
		alpha2[b[i] - 'a']++;
	}
	
	for (int i = 0; i < 26; i++) {
		res += abs(alpha1[i] - alpha2[i]);
	}

	cout << res;


	return 0;
}