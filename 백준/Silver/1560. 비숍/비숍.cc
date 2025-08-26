#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string n;
vector<int> ans, num1, num2;
int sum;

string sub_one(string s) {
	int i = s.size() - 1;
	while (i >= 0) {
		if (s[i] > '0') {
			s[i]--;
			break;
		}
		else {
			s[i] = '9';
			i--;
		}
	}
	if (s[0] == '0' && s.size() > 1) {
		s.erase(s.begin());
	}
	return s;
}

string sum_function(string s1, string s2) {
	string s, tmp;

	if (s1.size() < s2.size()) {
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	num1.push_back(0);
	num2.push_back(0);

	for (int i = 0; i < s1.size() - s2.size(); i++) {
		num2.push_back(0);
	}

	for (int i = 0; i < s1.size(); i++) {
		num1.push_back(s1[i] - '0');
	}

	for (int i = 0; i < s2.size(); i++) {
		num2.push_back(s2[i] - '0');
	}

	for (int i = s1.size(); i > 0; i--) {
		sum = num1[i] + num2[i];
		if (sum >= 10) {
			num1[i - 1]++;
			sum -= 10;
		}
		ans.push_back(sum);
	}

	if (num1.front() != 0) s.push_back('1');

	for (int i = ans.size() - 1; i >= 0; i--) {
		s.push_back(ans[i] + '0');
	}

	num1.clear();
	num2.clear();
	ans.clear();

	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	if (n == "1") {
		cout << 1;
		exit(0);
	}
	string nm = sub_one(n);
	cout << sum_function(nm, nm);
	
	return 0;
}