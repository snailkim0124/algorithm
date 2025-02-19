#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int dir;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') dir++;
        else if (s[i] == 'L') dir--;

        if (abs(dir) % 4 == 0) {
            if(dir > 0) cnt++;
            dir = 0;
        }
    }

    cout << cnt;
    
    return 0;
}