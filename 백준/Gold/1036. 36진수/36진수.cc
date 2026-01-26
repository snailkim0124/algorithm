#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;
string arr[40];

bool cmp(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() > b.size();
	return a > b;
}

int ctoint(char c) {
	if (isalpha(c)) return c - 'A' + 10;
	else return c - '0';
}

char inttoc(int num) {
	if (num < 10) return num + '0';
	else return num - 10 + 'A';
}

string add36(string a, string b) {
	string res = "";
	int i = a.size() - 1;
	int j = b.size() - 1;
	int tmp = 0;

	while (i >= 0 || j >= 0 || tmp) {
		int sum = tmp;
		if (i >= 0) {
			sum += ctoint(a[i--]);
		}
		if (j >= 0) {
			sum += ctoint(b[j--]);
		}

		tmp = sum / 36;
		sum %= 36;
		res += inttoc(sum);
	}
	reverse(all(res));

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	for (int i = 0; i <= 36; i++) {
		arr[i] = "0";
	}

	cin >> n;
	string sum = "0";

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		sum = add36(sum, s);
		for (int j = 0; j < s.size(); j++) {
			int num = ctoint(s[j]);

			int diff = 35 - num; // 변화량

			if (diff == 0) continue; // Z일때는 넘기기

			string diffs = "";
			diffs += inttoc(diff);
			for (int k = 0; k < s.size() - 1 - j; k++) {
				diffs += '0';
			}

			arr[num] = add36(arr[num], diffs);

		}
	}
	cin >> k;

	vector<string> v;
	for (int i = 0; i < 36; i++) {
		v.push_back(arr[i]);
	}

	sort(all(v), cmp);

	for (int i = 0; i < min(k, 36); i++) {
		sum = add36(sum, v[i]);
	}


	// 앞에 불필요한 0 제거
	string ans = "";
	bool flag = false;
	for (int i = 0; i < sum.size(); i++) {
		if (sum[i] != '0') {
			flag = true;
		}

		if (flag) {
			ans += sum[i];
		}
	}

	if (ans == "") cout << "0\n";
	else cout << ans << "\n";

	
	return 0;
}