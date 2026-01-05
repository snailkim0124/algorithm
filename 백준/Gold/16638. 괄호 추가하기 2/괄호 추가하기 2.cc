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
string s;
vector<int> num;
vector<char> op;
int visited[25];
int res = INT_MIN;

int calc(int a, char c, int b) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
	return 0;
}

int go() {
	vector<int> numt, numt2;
	vector<char> opt, opt2;

	for (int i = 0; i < num.size(); i++) {
		// 괄호 처리
		if (i < op.size() && visited[i]) {
			int tmp = calc(num[i], op[i], num[i + 1]);
			numt.push_back(tmp);
			i++;
		}
		else {
			numt.push_back(num[i]);
		}
	}

	for (int i = 0; i < op.size(); i++) {
		if (!visited[i]) {
			opt.push_back(op[i]);
		}
	}

	numt2.push_back(numt[0]);

	// 곱셈 우선
	for (int i = 0; i < opt.size(); i++) {
		if (opt[i] == '*') {
			int prev = numt2[numt2.size() - 1];
			numt2.pop_back();

			int next = numt[i + 1];
			numt2.push_back(prev * next);
		}
		else {
			numt2.push_back(numt[i + 1]);
			opt2.push_back(opt[i]);
		}
	}

	int res = numt2[0];
	for (int i = 0; i < opt2.size(); i++) {
		res = calc(res, opt2[i], numt2[i + 1]);
	}

	return res;
	

}

void dfs(int idx) {
	if (idx >= op.size()) {
		res = max(res, go());
		return;
	}

	// 1. 괄호 x
	dfs(idx + 1);

	// 2. 괄호 o
	visited[idx] = 1;
	dfs(idx + 2);
	visited[idx] = 0;

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
	
	dfs(0);

	cout << res << "\n";


	return 0;
}