#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s, res;
bool check[105];

bool prints() {
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (check[i]) {
            cout << s[i];
            flag = true;
        }
    }
    return flag;
}

void go(int left, int right) {
    char mn = 'a';
    int mnidx = -1;

    for (int i = left; i <= right; i++) {
        if (mn > s[i] && !check[i]) {
            mn = s[i];
            mnidx = i;
        }
    }

    if (mnidx == -1) return;
    check[mnidx] = 1;
    if(prints()) cout << "\n";

    go(mnidx + 1, right);
    go(left, mnidx - 1);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    go(0, s.size());
    
    return 0;
}