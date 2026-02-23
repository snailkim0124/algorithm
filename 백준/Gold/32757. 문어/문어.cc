#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	if (n <= k) {
		cout << 0 << "\n";
	}
	else if (n % 2 == 0) {
		cout << n << "\n";
	}
	else {
		if (k % 2 == 0) cout << n << "\n";
		else cout << n - 1 << "\n";
	}

	
    
	return 0;
}