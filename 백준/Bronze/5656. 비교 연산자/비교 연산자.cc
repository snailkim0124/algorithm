#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a, b;
string cmd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cnt = 0;
	while (1) {
		bool res;
		cnt++;
		cin >> a;
		cin >> cmd;
		cin >> b;

		if (cmd == ">") {
			res = (a > b);
		}
		else if (cmd == ">=") {
			res = (a >= b);
		}
		else if (cmd == "<") {
			res = (a < b);
		}
		else if (cmd == "<=") {
			res = (a <= b);
		}
		else if (cmd == "==") {
			res = (a == b);
		}
		else if (cmd == "!=") {
			res = (a != b);
		}
		else if (cmd == "E") {
			break;
		}


		if(res) cout << "Case " << cnt << ": " << "true" << "\n";
		else cout << "Case " << cnt << ": " << "false" << "\n";

	}

	return 0;
}