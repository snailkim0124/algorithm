#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else {
        return gcd(b, a % b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        bool point = false;
        int gwal = 0;

        string s;
        string num, sosu1, sosu2;
        string son, mom;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                point = true;
                continue;
            }
            if (!point) {
                num += s[i];
                continue;
            }
            if (s[i] == ')') {
                gwal++;
                continue;
            }
            if (gwal == 1) {
                sosu2 += s[i];
                continue;
            }
            if (s[i] == '(') {
                gwal++;
                continue;
            }
            if (gwal == 0) {
                sosu1 += s[i];
                continue;
            }
        }
        // cout << sosu1 << " : " << sosu2 << "\n";

        ll son_ll;

        if (sosu2.size() == 0) {
            son_ll = stoll(sosu1 + sosu2);
            mom += '1';
        }
        else {
            son_ll = stoll(sosu1 + sosu2) - stoll((sosu1 == "" ? "0" : sosu1));
        }

        for (int i = 0; i < sosu2.size(); i++) {
            mom += '9';
        }
        for (int i = 0; i < sosu1.size(); i++) {
            mom += '0';
        }

        // cout << sosu1 << " : " << sosu2 << " : " << son_ll << "\n";
        ll mom_ll = stoll(mom);
        cout << son_ll / gcd(son_ll, mom_ll) << "/" << mom_ll / gcd(son_ll, mom_ll) << "\n";
    }
    
    
    return 0;
}