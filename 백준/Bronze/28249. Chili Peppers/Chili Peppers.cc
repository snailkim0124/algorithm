#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<string, int> mp = {
    {"Poblano", 1500},
    {"Mirasol", 6000},
    {"Serrano", 15500},
    {"Cayenne", 40000},
    {"Thai", 75000},
    {"Habanero", 125000},
};

int t;
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        sum += mp[s];
    }

    cout << sum;

    return 0;
}