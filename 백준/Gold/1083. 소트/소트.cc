#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[55];
int cnt, s;

void go(int idx) {
	int maxidx = idx;
	int last = min(n - 1, idx + s - cnt);

	for (int i = idx; i <= last; i++) {
		if (arr[maxidx] < arr[i]) maxidx = i;
	}

	for (int i = maxidx; i > idx; i--) {
		swap(arr[i], arr[i - 1]);
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> s;

	for (int i = 0; i < n; i++) {
		go(i);
		if (cnt == s) break;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}