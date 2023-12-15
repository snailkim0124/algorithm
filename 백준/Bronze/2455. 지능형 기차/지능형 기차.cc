#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mx;
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		sum += b - a;
		mx = max(mx, sum);
	}

	cout << mx;


	return 0;
}