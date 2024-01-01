#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int k;
int a[50], b[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	a[1] = 0;
	a[2] = 1;
	b[1] = 1;
	b[2] = 1;
	cin >> k;

	for (int i = 1; i <= k - 2; i++) {
		a[i + 2] = a[i] + a[i + 1];
		b[i + 2] = b[i] + b[i + 1];
	}

	cout << a[k] << " " << b[k];

	return 0;
}