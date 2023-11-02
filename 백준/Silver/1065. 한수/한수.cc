#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int cnt;
bool check(string str) {
	int diff = str[0] - str[1];
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i + 1] != str[i] - diff) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	string n_str;
	n_str = to_string(n);
	if (n_str.size() == 1 || n_str.size() == 2) {
		cout << n;
	}
	else {
		for (int i = 100; i <= n; i++) {
			string i_str;
			i_str = to_string(i);
			if (check(i_str)) {
				cnt++;
			}
		}
		cout << 99 + cnt;
	}
	return 0;
}