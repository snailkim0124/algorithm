#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int k;

string change_string(string& s) {

	string ans = "";

	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) ans += tolower(s[i]);
		else if (s[i] == ' ') {
			if (i - 1 >= 0 && (isalpha(s[i - 1]) || isdigit(s[i - 1]))) {
				if (ans.back() == '(' || ans.back() == '[' || ans.back() == '{' || ans.back() == ')' || ans.back() == ']' || ans.back() == '}' || ans.back() == ',' || ans.back() == ';' || ans.back() == '.' || ans.back() == ':') continue;
				ans += ' ';
			}
		}
		else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			if (!ans.empty() && ans.back() == ' ') ans.pop_back();
			ans += '(';
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (!ans.empty() && ans.back() == ' ') ans.pop_back();
			ans += ')';
		}
		else if (s[i] == ',' || s[i] == ';') {
			if (!ans.empty() && ans.back() == ' ') ans.pop_back();
			ans += ',';
		}
		else {
			if (s[i] == '.' || s[i] == ':') {
				if (!ans.empty() && ans.back() == ' ') ans.pop_back();
			}
			else ans += s[i];
		}
	}

	while (!ans.empty() && ans.back() == ' ') ans.pop_back();

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	cin.ignore();
	for (int T = 1; T <= k; T++) {
		string a, b;
		getline(cin, a);
		getline(cin, b);
		string tmp_a = change_string(a);
		string tmp_b = change_string(b);

		//cout << "a : " << tmp_a << "\n" << "b : " <<  tmp_b << "\n\n";

		cout << "Data Set " << T << ": ";
		cout << (tmp_a == tmp_b ? "equal\n\n" : "not equal\n\n");
	}


	return 0;
}
