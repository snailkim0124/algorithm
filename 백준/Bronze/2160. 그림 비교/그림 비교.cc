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
char arr[55][10][10];
int mn = 987654321;
int res1, res2;

void check(int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (arr[x][i][j] != arr[y][i][j]) cnt++;
		}
	}

	if (mn > cnt) {
		mn = cnt;
		res1 = x;
		res2 = y;
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 7; j++) {
				cin >> arr[k][i][j];
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			check(i, j);
		}
	}
	
	cout << res1 << " " << res2 << "\n";
	
	return 0;
}