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
int cnt = 1;
int arr[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	arr[1] = cnt++;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			arr[i] = cnt;
			for (int j = i + i; j <= n; j += i) {
				arr[j] = cnt;
			}
			cnt++;
		}
	}

	cout << cnt - 1 << "\n";
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	


	return 0;
}