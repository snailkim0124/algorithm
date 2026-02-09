#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int a, b, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> k;
	if (a > b) swap(a, b);

	// 후공이 필승인 경우
	if (a == b) {
		if (k < 0) {
			if (a == 1 || k == -1) {
				cout << "First\n";
			}
			else {
				cout << "Second\n";
			}
		}
		else {
			cout << "Second\n";
		}
	}
	else {
		if (a == 0 && b == 1) {
			if (k < 0) {
				cout << "Second\n";
			}
			else cout << "First\n";
		}
		else {
			cout << "First\n";
		}
	}

	return 0;
}