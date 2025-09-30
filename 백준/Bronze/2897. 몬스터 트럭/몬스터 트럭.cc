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
char arr[55][55];
int res[5];

void go(int y, int x) {
	int sum = 0;
	for (int i = y; i < y + 2; i++) {
		for (int j = x; j < x + 2; j++) {
			if (arr[i][j] == '#') {
				return;
			}
			else if (arr[i][j] == 'X') {
				sum++;
			}
		}
	}

	res[sum]++;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < c - 1; j++) {
			go(i, j);
		}
	}


	for (int i = 0; i < 5; i++) {
		cout << res[i] << "\n";
	}
	
	return 0;
}