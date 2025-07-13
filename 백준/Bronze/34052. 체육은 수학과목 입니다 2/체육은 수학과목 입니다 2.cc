#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		sum += num;
	}

	if (sum + 300 <= 1800) cout << "Yes";
	else cout << "No";

	return 0;
}