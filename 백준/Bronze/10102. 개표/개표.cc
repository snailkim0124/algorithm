#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v;
string s;
int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v;
	cin >> s;
	for (int i = 0; i < v; i++) {
		if (s[i] == 'A') {
			a++;
		}
		else if (s[i] == 'B') {
			b++;
		}
	}

	if (a == b) cout << "Tie";
	else if (a > b) cout << "A";
	else cout << "B";
	

	return 0;
}