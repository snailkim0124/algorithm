#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
int n;
int visited[1005];
int arr[2][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[1][i];
			arr[0][i] = i;
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				cnt++; // 방문 안했을 때 카운트

				for (int j = i; !visited[j]; j = arr[1][j]) {
					visited[j] = 1; // 방문 처리
				}
			}
		}

		cout << cnt << "\n";
	}

	
	return 0;
}