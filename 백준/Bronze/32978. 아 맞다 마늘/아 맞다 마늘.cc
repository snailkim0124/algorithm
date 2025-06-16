#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    for (int i = 0; i < t - 1; i++) {
        string s;
        cin >> s;
        mp[s]--;
    }

    for (auto it : mp) {
        if (it.second == 1) {
            cout << it.first;
            break;
        }
    }

    return 0;
}