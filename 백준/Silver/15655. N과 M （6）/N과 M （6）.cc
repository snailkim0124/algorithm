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
int arr[10];
int res[10];
int visited[10];

void go(int depth, int prev) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i] && prev < arr[i]) {
			visited[i] = 1;
			res[depth] = arr[i];
			go(depth + 1, arr[i]); // 다음 칸을 채우러 감

			visited[i] = 0;
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