#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int package = 987654321;
int line = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		package = min(package, a);
		line = min(line, b);
	}

	if (package >= line * 6) {
		cout << n * line;
	}
	else {
		if (n % 6 == 0) {
			cout << min(package * (n / 6), line * n);
		}
		else {
			cout << min(package * (n / 6) + line * (n % 6), min(package * ((n / 6) + 1), line * n));
		}
	}

	return 0;
}