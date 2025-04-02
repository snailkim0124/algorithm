#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        int n;
        vector<pair<int, string>> v;

        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            int num;
            cin >> s >> num;
            v.push_back({ num, s });
        }

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < v.size(); i++) {
            cout << v[i].second;
            if (i != v.size() - 1) cout << ", ";
        }
        cout << "\n";
    }
    
   
    return 0;
}