#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[10];
int res[10];

void go(int depth, int idx) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = idx; i < n; i++) {
		if (tmp != arr[i]) {
			tmp = arr[i];
			res[depth] = arr[i];
			go(depth + 1, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	go(0, 0);
	
	return 0;
}