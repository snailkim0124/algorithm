#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'i') s[i] = 'e';
            else if (s[i] == 'I') s[i] = 'E';
            else if (s[i] == 'e') s[i] = 'i';
            else if (s[i] == 'E') s[i] = 'I';
        }

        cout << s << "\n";
    }
    
    return 0;
}