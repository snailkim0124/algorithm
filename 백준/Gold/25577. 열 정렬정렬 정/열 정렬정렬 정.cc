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
vector<int> a;
int visited[100005];
map<int, int> mp;
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	a.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> tmp = a;
	sort(all(tmp));

	for (int i = 0; i < tmp.size(); i++) {
		mp[tmp[i]] = i;
	}

	for (int i = 0; i < a.size(); i++) {
		a[i] = mp[a[i]]; // 좌표 압축
	}

	//for (auto it : a) {
	//	cout << it << " ";
	//}
	//cout << "\n";


	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int cnt = 0;
			for (int j = i; !visited[j]; j = a[j]) {
				visited[j] = 1;
				cnt++;
			}

			res += cnt - 1;
		}
	}

	cout << res << "\n";


	return 0;
}