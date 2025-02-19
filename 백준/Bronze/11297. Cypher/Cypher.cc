#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        int a, b, c;
        string s;

        cin >> a >> b >> c;
        if (!a && !b && !c) break;

        cin.ignore();
        getline(cin, s);

        int rotates = ((a + b + c) % 25) + 1;

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                s[i] = (char)((((s[i] - 'a') - rotates + 26) % 26) + 'a');
            }
        }

        cout  << s << "\n";

        

    }

    
    return 0;
}