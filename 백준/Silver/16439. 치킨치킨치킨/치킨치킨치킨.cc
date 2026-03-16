#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int arr[35][35];
int res;

int go(int a, int b, int c) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int mx = 0;
		mx = max({arr[i][a], arr[i][b], arr[i][c] });
		sum += mx;
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j =0 ; j< m; j++) {
			cin >> arr[i][j];
		}
	}

	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			for(int k = j + 1; k < m; k++) {
				res = max(res, go(i, j, k));
			}
		}
	}

	cout << res << "\n";


}