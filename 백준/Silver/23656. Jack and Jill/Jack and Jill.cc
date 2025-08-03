#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int x;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int left = 1;
	int right = 1000000000;

	while (cin >> x) {
		cnt++;
		if (cnt >= 30) {
			if (left <= x && x <= right) {
				cout << "=" << endl;
				break;
			}
		}

		if (x < left) cout << ">" << endl;
		else if (x > right) cout << "<" << endl;
		// 사이에 있는 경우
		else {
			if (right - x > x - left) {
				left = x + 1;
				cout << ">" << endl;
			}
			else {
				right = x - 1;
				cout << "<" << endl;
			}
		}
	}
	

	return 0;
}