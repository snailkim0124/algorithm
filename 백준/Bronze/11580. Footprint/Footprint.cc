#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string s;
set<pii> st;
int x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	st.insert({ 0, 0 });

	cin >> n >> s;

	for (auto& it : s) {
		if (it == 'E') x++;
		else if (it == 'W') x--;
		else if (it == 'N') y++;
		else if (it == 'S')y--;
		st.insert({ x,y });
	}
    
	cout << st.size();
   
    return 0;
}