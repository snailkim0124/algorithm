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
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		string num = to_string(i);

		int sum = i;
		for (int j = 0; j < num.size(); j++) {
			sum += num[j] - '0';
		}

		if (sum == n) {
			res = i;
			break;
		}
	}

	cout << res << "\n";
	
	return 0;
}