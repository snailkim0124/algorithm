#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
char d;
int cnt;

void check(string num) {
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == d) {
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		string num;
		num = to_string(i);
		check(num);
	}
	
	cout << cnt;
	return 0;
}