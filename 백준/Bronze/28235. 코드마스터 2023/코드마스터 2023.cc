#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	if (s == "SONGDO") cout << "HIGHSCHOOL";
	else if (s == "CODE") cout << "MASTER";
	else if (s == "2023") cout << "0611";
	else if (s == "ALGORITHM") cout << "CONTEST";

	return 0;
}