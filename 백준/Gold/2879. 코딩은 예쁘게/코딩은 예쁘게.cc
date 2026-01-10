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
int a[1005], b[1005];
int diff[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		diff[i] = b[i] - a[i];
	}

	int res = abs(diff[0]);

	for (int i = 1; i < n; i++) {
		// 이전이랑 부호가 다를 때
		if (diff[i] * diff[i - 1] <= 0) {
			res += abs(diff[i]);
		}
		else {
			if (abs(diff[i]) > abs(diff[i - 1])) {
				res += abs(diff[i]) - abs(diff[i - 1]);
			}
		}
	}
	cout << res << "\n";

	//for (int i = 0; i < n; i++) {
	//	cout << diff[i] << " ";
	//}
	//cout << "\n";

	return 0;
}