#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
set<string> st;
vector<string> v;

bool ispalindrome(string& word) {
	string word2 = word;
	reverse(word2.begin(), word2.end());

	if (word == word2) return true;
	else return false;
}

bool check(vector<string>& a, string b) {
	for (auto it : a) {
		if (it == b) return false;
	}
	return true;
}

bool cmp(string& a, string& b) {
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> s) {
		st.clear();
		v.clear();

		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				string tmp = s.substr(i, j + 1);
				if (!check(v, tmp)) continue;
				if (ispalindrome(tmp)) {
					v.push_back(tmp);
				}
			}
		}

		sort(v.begin(), v.end(), cmp);

		cout << v.size() << " - ";
		for (auto it : v) {
			cout << "\"" << it << "\" ";
		}
		cout << "\n";

	}

	return 0;
}