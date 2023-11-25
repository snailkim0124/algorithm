#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll x[10005];
ll y[10005];
double res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	x[n] = x[0];
	y[n] = y[0];

	for (int i = 0; i < n; i++) {
		res += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(res) / 2.0;

	return 0;
}