#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k, n;
string s[1005];
string order;
int ansidx = -1;
char ups[27], downs[27];
string ans;
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> n;
	cin >> order;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i][0] == '?') ansidx = i;
	}

	// cout << ansidx << "\n";

	for (int j = 0; j < k; j++) {
		int now = j;
		for (int i = 0; i < ansidx; i++) {
			if (now - 1 >= 0 && s[i][now - 1] == '-') now--;
			else if (s[i][now] == '-') now++;
		}
		ups[now] = j + 'A';
	}

	for (int j = 0; j < k; j++) {
		int now = j;
		for (int i = n - 1; i > ansidx; i--) {
			if (now - 1 >= 0 && s[i][now - 1] == '-') now--;
			else if (s[i][now] == '-') now++;
		}
		downs[now] = order[j];
	}

	//for (int i = 0; i < k; i++) {
	//	cout << ups[i];
	//}
	//cout << "\n";

	//for (int i = 0; i < k; i++) {
	//	cout << downs[i];
	//}
	//cout << "\n";

	int idx = 0;
	while (idx <= k - 1) {
		if (ups[idx] == downs[idx]) ans += '*';
		else if (ups[idx] == downs[idx + 1] && ups[idx + 1] == downs[idx]) {
			ans += "-*";
			idx++;
		}
		else {
			flag = true;
			break;
		}
		idx++;
	}

	if (flag) {
		for (int i = 0; i < k - 1; i++) {
			cout << "x";
		}
	}
	else {
		for (int i = 0; i < k - 1; i++) {
			cout << ans[i];
		}
	}



	return 0;
}