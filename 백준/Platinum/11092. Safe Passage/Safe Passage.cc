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
int sum;
int arr[20];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	while (n >= 4) {
		// 1. 1번이 왔다갔다
		int dist1 = arr[0] * 2 + arr[n - 1] + arr[n - 2];
		// 2. 1,2번이 왔다갔다
		int dist2 = arr[1] + arr[0] + arr[n - 1] + arr[1];

		sum += min(dist1, dist2);
		n -= 2;
	}

	if (n == 3) {
		sum += arr[0] + arr[1] + arr[2];
	}
	else if (n == 2) {
		sum += arr[1];
	}
	else {
		sum += arr[0];
	}

	cout << sum << "\n";

	return 0;
}