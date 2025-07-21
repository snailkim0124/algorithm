#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string n;
		int sum = 0;
		cin >> n;
		if (n == "0") break;

		for (auto it : n) {
			if (it == '0') sum += 4;
			else if (it == '1') sum += 2;
			else sum += 3;
		}

		cout << sum + n.size() + 1 << "\n";
	}


	return 0;
}