#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "P=NP") {
            cout << "skipped\n";
        }
        else {
            auto it = s.find('+');
            string a = s.substr(0, it);
            string b = s.substr(it + 1);

            cout << stoi(a) + stoi(b) << "\n";
        }
    }


    return 0;
}