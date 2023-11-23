#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
string s;
string d = " ";
int cnt;

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	ll pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.size());
	}
	ret.push_back(input);
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	cin.ignore();
	for (int i = 1; i <= t; i++) {
		getline(cin, s);
		vector<string> a = split(s, d);
		reverse(a.begin(), a.end());
		cout << "Case #" << i << ": ";
		for (auto it : a) {
			cout << it << " ";
		}
		cout << "\n";
	}


	return 0;
}