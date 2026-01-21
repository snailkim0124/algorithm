#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int w, n;
int arr[5005];
int visited[800005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];

			if (sum >= w) continue;

			// 필요한 부분 매꿀 수 있는지
			if (visited[w - sum]) {
				cout << "YES\n";
				exit(0);
			}
		}

		// i보다 작은 인덱스 추가
		for (int j = 0; j < i; j++) {
			int sum = arr[i] + arr[j];
			if (w > sum) {
				visited[sum] = 1;
			}
		}
	}

	cout << "NO\n";

	return 0;
}