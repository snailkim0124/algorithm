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
int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int cmd, i, x;
		cin >> cmd >> i;
		if (cmd == 1) {
			cin >> x;
			arr[i] |= (1 << x);
		}
		else if (cmd == 2) {
			cin >> x;
			arr[i] &= ~(1 << x);
		}
		else if (cmd == 3) {
			arr[i] <<= 1;
			arr[i] &= ~(1 << 21); // 모듈러
		}
		else if (cmd == 4) {
			arr[i] >>= 1;
			arr[i] &= ~(1 << 0); // 모듈러
		}
	}
	
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(arr[i]);
		//cout << arr[i] << "\n";
	}

	cout << s.size() << "\n";

	
	return 0;
}