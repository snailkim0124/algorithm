#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int suma = 100;
int sumb = 100;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			suma -= b;
		}
		else if (a > b) {
			sumb -= a;
		}
	}

	cout << suma << "\n" << sumb;

	return 0;
}