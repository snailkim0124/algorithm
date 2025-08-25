#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;
double arr[1005];
double f, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	f = n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		double tmp = 0;
		tmp += f * (1 - (arr[i] / n)); // 앞
		tmp += b * (arr[i] / n); // 뒤

		f = tmp;
		b = n - tmp;
	}

	cout << fixed;
	cout.precision(9);
	cout << f << "\n";
	
	return 0;
}