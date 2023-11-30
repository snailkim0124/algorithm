#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[50];
int res = 987654321;
string s;

void go(int here) {
	if (here == n + 1) {
		int sum = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
			int cnt = 0; 
			for (int j = 0; j <= n; j++) {
				if (arr[j] & i) cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		res = min(res, sum);
		return;
	}

	go(here + 1);
	arr[here] = ~arr[here];
	go(here + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int val = 1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') arr[i] |= val;
			val *= 2;
		}
	}

	go(1);

	cout << res;

	return 0;
}