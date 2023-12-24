#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s.substr(i));
	}

	sort(v.begin(), v.end());

	for (auto it : v) {
		cout << it << "\n";
	}

	return 0;
}