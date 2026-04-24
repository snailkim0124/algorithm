#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (auto it : s) {
		if (isupper(it)) {
			sum += it - 'A' + 27;
		}
		else if (islower(it)) {
			sum += it - 'a' + 1;
		}
	}

	for (int i = 2; i * i <= sum; i++) {
		if (sum % i == 0) {
			cout << "It is not a prime word.\n";
			exit(0);
		}
	}

	cout << "It is a prime word.\n";
	
	return 0;
}