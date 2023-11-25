#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, w, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> w >> h;
	int mx = (int)sqrt(w * w + h * h);
	while (n--) {
		int num;
		cin >> num;
		if (num <= mx) cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}