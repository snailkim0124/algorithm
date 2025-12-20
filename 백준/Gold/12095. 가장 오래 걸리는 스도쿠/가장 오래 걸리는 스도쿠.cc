#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string arr[15] = {
	"005300000",
	"800000020",
	"070010500",
	"400005300",
	"010070006",
	"003200080",
	"060500009",
	"004000060",
	"000009700",
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;
}