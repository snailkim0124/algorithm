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
int visited[100005];
int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int now = i;

			while (1) {
				visited[now] = i;
				int next = arr[now];

				// 사이클 찾음
				if (visited[next] == i) {
					int cnt = 1;
					for (int j = arr[next]; j != next; j = arr[j]) {
						cnt++;
					}

					res += cnt;
					break;
				}

				// 없음
				if (visited[next] != 0) break;

				now = next;
			}
		}
	}

	cout << res << "\n";

	return 0;
}