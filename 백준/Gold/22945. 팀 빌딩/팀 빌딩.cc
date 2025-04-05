#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
ll arr[100005];
ll mx = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll left = 0;
    ll right = n - 1;

    while (left < right) {
        
        mx = max(mx, (right - left - 1) * min(arr[left], arr[right]));

        if(arr[left] < arr[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << mx;

    
    
    return 0;
}