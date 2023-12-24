#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check;
char s[100];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 5; i++) {
		cin >> s;
		if (strstr(s, "FBI") != NULL) {
			v.push_back(i);
			check = true;
		}
	}

	if (!check) cout << "HE GOT AWAY!";
	else {
		for (auto it : v) {
			cout << it << " ";
		}
	}

	return 0;
}