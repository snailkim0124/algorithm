#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

map<string, string> mp = {
    {"Algorithm","204"},
    {"DataAnalysis","207"},
    {"ArtificialIntelligence", "302"},
    {"CyberSecurity", "B101"},
    {"Network", "303"},
    {"Startup", "501"},
    {"TestStrategy", "105"},
};

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << mp[s] << "\n";
    }
    
    
    return 0;
}