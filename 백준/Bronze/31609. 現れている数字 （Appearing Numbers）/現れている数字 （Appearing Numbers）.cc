#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
set<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        st.insert(num);
    }

    for (auto it : st) {
        cout << it << "\n";
    }
    
    return 0;
}