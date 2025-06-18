#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;

vector<string> split(const string& input, string delimiter) {
	vector<string> result;
	auto start = 0;
	auto end = input.find(delimiter);
	while (end != string::npos) {
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start));
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	vector<string> para = split(s, "x");

	if (para.size() == 1) cout << 0;
	else if (para[0] == "") {
		cout << 1;
	}
	else if (para[0] == "-") {
		cout << -1;
	}
	else cout << para[0];

	return 0;
}
