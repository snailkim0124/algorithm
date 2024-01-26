#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int t;
string sound, s;
vector<string> animal;

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
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
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string d = " ";
	cin >> t;
	cin.ignore();
	while (t--) {
		sound.clear();
		s.clear();
		animal.clear();

		getline(cin, sound);
		vector<string> res = split(sound, d);

		while (getline(cin, s)) {
			if (s == "what does the fox say?") break;
			// cout << s << "\n";
			vector<string> a = split(s, d);
			if (a[1] == "goes") animal.push_back(a[2]);
		}

		for (auto it : res) {
			if (find(animal.begin(), animal.end(), it) == animal.end()) {
				cout << it << " ";
			}
		}
		cout << "\n";
	}

	
	return 0;
}