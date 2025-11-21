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
int arr[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	while (1) {
		memset(arr, 0, sizeof(arr));
		cin >> n;

		if (!n) break;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (sum + arr[i] <= 300) sum += arr[i];
		}

		cout << sum << "\n";

	}


	return 0;
}