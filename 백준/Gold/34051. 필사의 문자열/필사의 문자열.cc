#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string s, rs;
string mx;
int idx = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	mx = s;
	rs = s;
	sort(rs.begin(), rs.end(), greater<>()); // 최대인 경우

	for (int i = 0; i < n; i++) {
		if (rs[i] != s[i]) {
			for (int j = i + 1; j < n; j++) {
				if (rs[i] == s[j]) {
					string tmp = s;
					reverse(tmp.begin() + i, tmp.begin() + j + 1);
					if (mx < tmp) mx = tmp;
				}
			}
		}
	}

	cout << mx;
	
	return 0;
}