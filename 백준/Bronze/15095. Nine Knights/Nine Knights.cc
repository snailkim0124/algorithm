#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

char arr[10][10];
const int dy[8] = {-2,-2,-1,1,2,2,1,-1};
const int dx[8] = {-1,1,2,2,1,-1,-2,-2};
int cnt;

bool check(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		if (arr[ny][nx] == 'k') return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 'k') {
				if (!check(i, j)) {
					cout << "invalid\n";
					exit(0);
				}
				else cnt++;
			}
		}
	}

	if (cnt == 9) cout << "valid\n";
	else cout << "invalid\n";

	
	return 0;
}
