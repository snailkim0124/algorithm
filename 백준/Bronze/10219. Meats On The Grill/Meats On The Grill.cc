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

int t;
char arr[15][15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		int h, w;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < w; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	

	return 0;
}