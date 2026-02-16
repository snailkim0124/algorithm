#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	string n;
	cin >> n;

	if (n.back() == '5') {
		cout << 0 << " " << 5 << "\n";
		return;
	}

	if (n[n.size() - 2] == '5') {
		cout << n.size() << " " << 5 << "\n";
		return;
	}

	int idx1 = -1;
	int idx2 = -1;
	ll sum = 0;
	for (int i = 0; i < n.size(); i++) {
		sum += n[i] - '0';
		if (n[i] == '1') idx1 = i + 1;
		else if (n[i] == '5') idx2 = i + 1;
	}

	if (sum % 3 == 0) {
		cout << 0 << " " << 3 << "\n";
	}
	else if (idx1 != -1 && (sum - 1) % 3 == 0) {
		cout << idx1 << " " << 3 << "\n";
	}
	else if (idx2 != -1 && (sum - 5) % 3 == 0) {
		cout << idx2 << " " << 3 << "\n";
	}
	else {
		// 11의 배수 : 11111, 111111111
		if (n.size() % 2 == 0) {
			cout << 0 << " " << 11 << "\n";
		}
		else {
			cout << idx1 << " " << 11 << "\n";
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}