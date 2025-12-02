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
int cnt[5];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "1/4") cnt[1]++;
		else if (s == "1/2") cnt[2]++;
		else if (s == "3/4") cnt[3]++;
	}

	// 1/2 + 1/2
	res += cnt[2] / 2;
	cnt[2] %= 2;

	// 1/4 + 3/4
	int tmp = min(cnt[1], cnt[3]);
	res += tmp;
	cnt[1] -= tmp;
	cnt[3] -= tmp;

	// 1/2 + 1/4 + 1/4
	int tmp2 = min(cnt[1] / 2, cnt[2]);
	res += tmp2;
	cnt[1] -= tmp2 * 2;
	cnt[2] -= tmp2;

	// 1/4 + 1/4 + 1/4 + 1/4
	int tmp3 = cnt[1] / 4;
	res += tmp3;
	cnt[1] -= tmp3 * 4;


	// 나머지 처리
	// 1/4 + 1/2
	int tmp4 = min(cnt[1], cnt[2]);
	res += tmp4;
	cnt[1] -= tmp4;
	cnt[2] -= tmp4;

	// 1/4
	if (cnt[1]) {
		res += cnt[1] / 4 + 1;
		cnt[1] = 0;
	}

	for (int i = 1; i <= 3; i++) {
		res += cnt[i];
	}

	//for (int i = 1; i <= 3; i++) {
	//	cout << i << " : " << cnt[i] << "\n";
	//}
	cout << res << "\n";
	
	return 0;
}