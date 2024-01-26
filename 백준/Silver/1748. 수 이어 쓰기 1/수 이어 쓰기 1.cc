#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int n;
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i *= 10) {
		res += n - i + 1;
	}
	cout << res;

	return 0;
}