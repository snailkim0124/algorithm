#include <bits/stdc++.h>

using namespace std;
int mx;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		sum += b - a;
		mx = max(mx, sum);
	}

	cout << mx;
	

	return 0;
}