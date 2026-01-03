#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int h[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		sum += h[i];
	}

	if (sum % 3 != 0) {
		cout << "NO\n";
		exit(0);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += h[i] / 2;
	}

	// cout << cnt << " : " << sum / 3 << "\n";
	
	if (cnt < sum / 3) {
		cout << "NO\n";
	}
	else cout << "YES\n";

	return 0;
}