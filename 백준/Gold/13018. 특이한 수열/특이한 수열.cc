#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	if (n == k) {
		cout << "Impossible";
		exit(0);
	}

	cout << n - k << " ";
	
	for (int i = 1; i < n - k; i++) {
		cout << i << " ";
	}
	for (int i = n - k + 1; i <= n; i++) {
		cout << i << " ";
	}
	
	return 0;
}
