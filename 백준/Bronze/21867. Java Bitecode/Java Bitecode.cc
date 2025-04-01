#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string s, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'J' && s[i] != 'A' && s[i] != 'V') ans += s[i];
    }

    if (ans.empty()) cout << "nojava";
    else cout << ans;
   
    return 0;
}