#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int cnt = 0;
int visited[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int n;
		string s;
		cin >> n;
		if (n == 0) break;
		cin.ignore();

		getline(cin, s);

		if (s == "too high") {
			cnt++;
			for (int i = 1; i < n; i++) {
				visited[i]++;
			}
		}
		else if (s == "too low") {
			cnt++;
			for (int i = n + 1; i <= 10; i++) {
				visited[i]++;
			}
		}
		else if (s == "right on") {
			if (cnt == visited[n]) {
				cout << "Stan may be honest\n";
			}
			else cout << "Stan is dishonest\n";

			memset(visited, 0, sizeof(visited));
			cnt = 0;
		}
		
	}
	
	
	return 0;
}