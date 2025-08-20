#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

map<int, string> mp = {
	{1 , "12 1600"},
	{2 , "11 894"},
	{3 , "11 1327"},
	{4 , "10 1311"},
	{5 , "9 1004"},
	{6 , "9 1178"},
	{7 , "9 1357"},
	{8 , "8 837"},
	{9 , "7 1055"},
	{10 , "6 556"},
	{11 , "6 773"},
};

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cout << mp[n] << "\n";
	
	return 0;
}