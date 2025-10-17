#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<int> v;
int dp[5][5][100005];

int score(int a, int b) {
	if (a == 0) return 2;
	if (a == b) return 1;
	if (abs(a - b) == 2) return 4;
	return 3;
}

int go(int y, int x, int depth) {
	if (depth == v.size()) return 0;
	if (dp[y][x][depth] != -1) return dp[y][x][depth];

	int l = go(v[depth], x, depth + 1) + score(y, v[depth]);
	int r = go(y, v[depth], depth + 1) + score(x, v[depth]);

	return dp[y][x][depth] = min(l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int num;
		cin >> num;
		if (!num) break;
		v.push_back(num);
	}

	memset(dp, -1, sizeof(dp));


	cout << go(0, 0, 0) << "\n";

	return 0;
}