#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<pair<char, char>> ans;

void hanoi(int n, int a, int b, int c) {
	if (n == 0) return;
	hanoi(n - 1, a, c, b);
	ans.push_back({ (char)('A' + a), (char)('A' + c) });
	hanoi(n - 1, b, a, c);
}

void go(int n, int a, int b, int c, int d) {
	if (n == 0) return;
	if (n == 1) {
		ans.push_back({ (char)('A' + a), (char)('A' + d) });
		return;
	}

	hanoi(n - 2, a, c, b);
	ans.push_back({ (char)('A' + a), (char)('A' + c) });
	ans.push_back({ (char)('A' + a), (char)('A' + d) });
	ans.push_back({ (char)('A' + c), (char)('A' + d) });
	go(n - 2, b, a, c, d);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	go(n, 0, 1, 2, 3);

	cout << ans.size() << "\n";
	for (auto [a, b] : ans) {
		cout << a << " " << b << "\n";
	}

	return 0;
}