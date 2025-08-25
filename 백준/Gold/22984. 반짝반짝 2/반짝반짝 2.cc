#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
double arr[100005];
double res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		res += arr[i];
		if (i == 0) continue;
		res += arr[i - 1] * (1 - arr[i]) + (1 - arr[i - 1]) * arr[i];
	}

	cout << fixed;
	cout.precision(6);
	cout << res << "\n";


	return 0;
}