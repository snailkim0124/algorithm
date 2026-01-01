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
int arr[1005][1005];
vector<int> ans;
int nxt[1005];

void dfs(int now) {

	while (nxt[now] <= n) {
		int i = nxt[now];

		if (arr[now][i]) {
			arr[now][i]--;
			arr[i][now]--;
			dfs(i);
		}
		else nxt[now]++;
	}

	ans.push_back(now);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	int odd = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			cnt += arr[i][j];
		}

		if (cnt % 2 == 1) odd++;
	}

	// 홀수인 차수가 0개 or 2개여야 함 
	if (!odd) {
		for (int i = 1; i <= n; i++) {
			nxt[i] = 1;
		}
		dfs(1);

		reverse(all(ans));
		for (auto it : ans) {
			cout << it << " ";
		}
		cout << "\n";

	}
	else {
		cout << -1 << "\n";
	}

	
	return 0;
}