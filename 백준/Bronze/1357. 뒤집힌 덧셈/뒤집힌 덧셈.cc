#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;
	string x_tmp, y_tmp;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int ans = stoi(x) + stoi(y);
	string ans_str = to_string(ans);
	reverse(ans_str.begin(), ans_str.end());
	ans = stoi(ans_str);
	cout << ans;

	
	return 0;
}