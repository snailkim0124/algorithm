#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[1005];
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                v.push_back({ j, j + 1 });
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << v.size() << "\n";
    for (auto it : v) {
        cout << it.first << " " << it.second << "\n";
    }
    
    return 0;
}