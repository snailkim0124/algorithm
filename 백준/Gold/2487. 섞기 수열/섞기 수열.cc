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
int arr[20005];
int visited[20005];
int res = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}


	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int cnt = 0; // 각 순열 그래프의 크기
			for (int j = i; !visited[j]; j = arr[j]) {
				visited[j] = 1;
				cnt++;
			}

			res = lcm(res, cnt);
		}
	}

	// 최소공배수가 답
	cout << res << "\n";

	return 0;
}