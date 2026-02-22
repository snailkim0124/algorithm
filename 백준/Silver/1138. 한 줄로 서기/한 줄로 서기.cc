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
int arr[15], ans[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (ans[j] == 0) {
				if (cnt == arr[i]) {
					ans[j] = i;
					break;
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}