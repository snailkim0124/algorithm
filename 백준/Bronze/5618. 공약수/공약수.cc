#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[5];
int GCD = 1;
set<int> st;

int gcd(int a, int b) {
    if (b == 0) return a;
    else {
        return gcd(b, a % b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    GCD = gcd(arr[0], arr[1]);
    if(n == 3) GCD = gcd(GCD, arr[2]);

    for (int i = 1; i * i <= GCD; i++) {
        if (GCD % i == 0) {
            st.insert(i);
            st.insert(GCD / i);
        }
    }
    
    for (auto it : st) {
        cout << it << "\n";
    }

    return 0;
}