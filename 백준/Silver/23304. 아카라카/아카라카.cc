#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int palinsize;

bool ispalin(string s2) {
    int palinsize = s2.size() / 2;
    if (s2.size() == 1) return true;

    else {
        string tmp = s2;
        reverse(tmp.begin(), tmp.end());
        if (tmp == s2) return ispalin(s2.substr(0, palinsize));
        else return false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    
    if (ispalin(s)) cout << "AKARAKA";
    else cout << "IPSELENTI";
    
    return 0;
}