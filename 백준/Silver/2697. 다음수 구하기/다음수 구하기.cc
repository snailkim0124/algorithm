#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	string a;
	cin >> a;

	// 마지막으로 증가하는 부분 찾기
	int idx = -1;
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] < a[i + 1]) idx = i;
	}

	if (idx == -1) {
		cout << "BIGGEST" << "\n";
		return;
	}

	string ans = a.substr(0, idx);
	string tmp = a.substr(idx); // 조작할 부분

	vector<int> cnt(10, 0);
	for (int i = 0; i < tmp.size(); i++) {
		cnt[tmp[i] - '0']++;
	}

	// 조작할 인덱스 숫자보다 큰 그나마 작은 숫자 찾기
	for (int i = a[idx] - '0' + 1; i < 10; i++) {
		if (cnt[i]) {
			cnt[i]--;
			ans += ('0' + i);
			break;
		}
	}

	// 나머지 처리
	for (int i = 0; i < 10; i++) {
		while (cnt[i]) {
			ans += ('0' + i);
			cnt[i]--;
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}