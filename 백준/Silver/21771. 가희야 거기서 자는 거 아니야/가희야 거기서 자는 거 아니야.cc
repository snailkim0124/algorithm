#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c;
int gr, gc, pr, pc;
char arr[105][105];

bool check(int y, int x) {
	if (y + pr > r || x + pc > c) return true;

	for (int i = y; i < y + pr; i++) {
		for (int j = x; j < x + pc; j++) {
			if (arr[i][j] == 'G') {
				return true;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	cin >> gr >> gc >> pr >> pc;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'P') {
				if (check(i, j)) {
					cout << 1 << "\n";
					exit(0);
				}
				else {
					cout << 0 << "\n";
					exit(0);
				}

			}
		}
	}


	return 0;
}