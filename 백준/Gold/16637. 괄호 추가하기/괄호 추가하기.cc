#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string s;
vector<int> num;
vector<char> op;
int res = INT_MIN;

int calc(int a, char c, int b) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
	return 0;
}

void go(int idx, int val) {
	if (idx == num.size() - 1) {
		res = max(res, val);
		return;
	}

	go(idx + 1, calc(val, op[idx], num[idx + 1]));

	if (idx + 2 <= num.size() - 1) {
		int next = calc(num[idx + 1], op[idx + 1], num[idx + 2]);
		go(idx + 2, calc(val, op[idx], next));
		return;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else op.push_back(s[i]);
	}
	go(0, num[0]);
	cout << res;


	return 0;
}