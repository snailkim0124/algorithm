#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') b++;
        else if (s[i] == 'C') c++;
    }
    
    cout << b / 2 + c / 2;

    
    return 0;
}