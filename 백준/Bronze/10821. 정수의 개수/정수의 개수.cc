#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
string d = ",";
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

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') cnt++;
	}

	cout << cnt +1;

	return 0;
}