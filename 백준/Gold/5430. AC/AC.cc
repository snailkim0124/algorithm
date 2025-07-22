#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
string p;
int n;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		bool rev = false;
		bool check = false;
		deque<int> dq;

		cin >> p;
		cin >> n;
		cin >> s;

		string num = "";
		for (char c : s) {
			if (isdigit(c)) num += c;
			else {
				if (!num.empty()) {
					dq.push_back(stoi(num));
					num = "";
				}
			}
		}

		for (auto it : p) {
			if (it == 'R') {
				rev = !rev;
			}
			else if (it == 'D') {
				if (dq.empty()) {
					check = true;
					break;
				}
				else {
					if (rev) dq.pop_back();
					else dq.pop_front();
				}
			}
		}

		if (check) cout << "error" << "\n";
		else {
			cout << "[";
			if (rev) reverse(dq.begin(), dq.end());
			if (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
			}
			while (!dq.empty()) {
				cout << "," << dq.front();
				dq.pop_front();
			}
			cout << "]";

			cout << "\n";
		}

	}


	return 0;
}