#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c;
string ans;
int arr[1005][1005];
int mn = 987654321;
int mny, mnx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (mn > arr[i][j] && (i + j) % 2 == 1) {
				mn = arr[i][j];
				mny = i;
				mnx = j;
			}
		}
	}

	// 짝짝일때(한칸 빼고 지나기)
	if (r % 2 == 0 && c % 2 == 0) {
		int end = 0;
		if (mny % 2 == 1) end = mny - 1;
		else end = mny;

		for (int i = 0; i < end; i++) {
			for (int j = 0; j < c - 1; j++) {
				if (i % 2 == 0) ans += "R";
				else ans += "L";
			}
			ans += "D";
		}

		for (int j = 0; j < mnx; j++) {
			if (j % 2 == 0) ans += "DR";
			else ans += "UR";
		}

		for (int j = mnx; j < c - 1; j++) {
			if (j % 2 == 0) ans += "RD";
			else ans += "RU";
		}

		for (int i = end + 2; i < r; i++) {
			ans += "D";
			for (int j = 0; j < c - 1; j++) {
				if (i % 2 == 0) ans += "L";
				else ans += "R";
			}
		}
	}
	// 아닐때 -> 홀수 방향으로 가면됨 (전부 지나기)
	else if (r % 2 == 1) {
		for (int i = 0; i < r; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < c - 1; j++) {
					ans += "R";
				}
			}
			else {
				for (int j = 0; j < c - 1; j++) {
					ans += "L";
				}
			}
			if(i != r - 1) ans += "D";
		}
		
	}
	else if (c % 2 == 1) {
		for (int j = 0; j < c; j++) {
			if (j % 2 == 0) {
				for (int i = 0; i < r - 1; i++) {
					ans += "D";
				}
			}
			else {
				for (int i = 0; i < r - 1; i++) {
					ans += "U";
				}
			}
			if (j != c - 1) ans += "R";
		}
	}
	
	cout << ans << "\n";

	return 0;
}