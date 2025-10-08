#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
ll arr[105];
int visited[105];
vector<ll> ans;

void go(int now, int depth) {
	if (depth == n - 1) {
		for (auto it : ans) {
			cout << it << " ";
		}
		cout << "\n";
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		if (arr[now] % 3 == 0 && arr[now] / 3 == arr[i]) {
			visited[i] = 1;
			ans.push_back(arr[i]);
			go(i, depth + 1);
			ans.push_back(arr[i]);
			visited[i] = 0;
		}

		if (arr[now] * 2 == arr[i]) {
			visited[i] = 1;
			ans.push_back(arr[i]);
			go(i, depth + 1);
			ans.push_back(arr[i]);
			visited[i] = 0;
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		ans.clear();
		visited[i] = 1;
		ans.push_back(arr[i]);

		go(i, 0);
	}

	return 0;
}