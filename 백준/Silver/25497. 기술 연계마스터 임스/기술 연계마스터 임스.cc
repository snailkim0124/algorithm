#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
string s;
stack<char> st1, st2;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'S') {
			st1.push(s[i]);
		}
		else if (s[i] == 'K') {
			if (!st1.empty() && st1.top() == 'S') {
				st1.pop();
				cnt++;
			}
			else break;
		}
		else if (s[i] == 'L') {
			st2.push(s[i]);
		}
		else if (s[i] == 'R') {
			if (!st2.empty() && st2.top() == 'L') {
				st2.pop();
				cnt++;
			}
			else break;
		}
		else {
			cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}