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
int arr[100005];
int cnt[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 1; j * j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				res += cnt[j];
				if (j != arr[i] / j) res += cnt[arr[i] / j];
			}
		}

		cout << res - 1 << "\n";
	}
	
	return 0;
}