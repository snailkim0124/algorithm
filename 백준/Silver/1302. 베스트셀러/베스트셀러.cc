#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<string, int> mp;
int n;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    for (auto it : mp) cnt = max(cnt, it.second);
    for (auto it : mp) {
        if (it.second == cnt) {
            cout << it.first;
            break;
        }
    }

    return 0;
}
