#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<pair<string, string>> v;
map<string, int> mp;
int arr[25];
int visited[25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int T = 1; ; T++) {
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		int n;
		cin >> n;
		if (!n) break;

		v.resize(n);
		int idx = 1;
		for (int i = 1; i <= n; i++) {
			string a, b;
			cin >> a >> b;
			mp[a] = idx++; // 인덱스 형태로 바꾸기
			v.push_back({ a, b });
		}

		// 연결하기
		for (auto [a, b] : v) {
			arr[mp[a]] = mp[b];
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				cnt++;
				for (int j = i; !visited[j]; j = arr[j]) {
					visited[j] = 1;
				}
			}
		}
		cout << T << " " << cnt << "\n";
	}

	return 0;
}