#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int arr[15][15] = {
	{ 0, 3, 5, 4, 6, 9, 2, 7, 8 },
	{ 7, 8, 2, 1, 0, 5, 6, 0, 9 },
	{ 0, 6, 0, 2, 7, 8, 1, 3, 5 },
	{ 3, 2, 1, 0, 4, 6, 8, 9, 7 },
	{ 8, 0, 4, 9, 1, 3, 5, 0, 6 },
	{ 5, 9, 6, 8, 2, 0, 4, 1, 3 },
	{ 9, 1, 7, 6, 5, 2, 0, 8, 0 },
	{ 6, 0, 3, 7, 0, 1, 9, 5, 2 },
	{ 2, 5, 8, 3, 9, 4, 7, 6, 0 },
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << 0 << " ";
		}
		cout << "\n";
	}
	

	return 0;
}