#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	ll pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool check = false;
	string s, ans;
	string d = ":";
	cin >> s;
	if (s.find("::") != string::npos) {
		s.replace(s.find("::"), 2, ":####:");
		check = true;
	}

	vector<string> a = split(s, d);

	string origin = "####";
	string tmp = "";

	if (check) {
		if (a.size() >= 9) {
			tmp += "0000";

		}
		else {
			for (int i = 0; i <= 8 - a.size(); i++) {
				tmp += "0000:";
			}
		}
		replace(a.begin(), a.end(), origin, tmp);
	}

	/*for (auto it : a) {
		if (it == "0000") {
			cout << "good\n";
			break;
		}
		cout << it << " ";
	}*/
	bool check2 = false;
	int size = a.size();
	if (a.size() >= 9) {
		if (a[7] == "0000") {
			size = 8;
		}
		if (a[1] == "0000") {
			check2 = true;
		}
	}

	for (int i = 0; i < size; i++) {
		if (check2 && i == 0) continue;
		if (a[i].size() < 4) {
			for (int j = 0; j < 4 - a[i].size(); j++) {
				ans += "0";
			}
		}
		ans += a[i];
		if (i != size - 1 && a[i].size() <= 4) {
			ans += ":";
		}
	}
	
	cout << ans;

	return 0;
}