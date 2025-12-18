#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int u;
	cin >> u;
	while (u--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> pref(n, 0);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		// 뒤와 차이를 저장
		pref[0] = a[0];
		for (int i = 1; i < n; i++) {
			pref[i] = a[i] - a[i - 1];
		}

		// 뒤에서 부터 홀수 인덱스 조사(님게임) -> 선공이 조절 가능
		int x = 0;
		for (int i = n - 1; i >= 0; i -= 2) {
			x ^= pref[i];
		}

		cout << (x ? "TAK" : "NIE") << "\n";
	}




	return 0;
}