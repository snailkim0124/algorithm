#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[300005];
vector<int> odd, even;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool flag1 = false;
    for (int i = 0; i < n; i++) {
        if (!flag1 && arr[i] % 2 == 1) {
            odd.push_back(arr[i]);
            flag1 = !flag1;
        }
        else if (flag1 && arr[i] % 2 == 0) {
            odd.push_back(arr[i]);
            flag1 = !flag1;
        }
    }

    bool flag2 = false;
    for (int i = 0; i < n; i++) {
        if (!flag2 && arr[i] % 2 == 0) {
            even.push_back(arr[i]);
            flag2 = !flag2;
        }
        else if (flag2 && arr[i] % 2 == 1) {
            even.push_back(arr[i]);
            flag2 = !flag2;
        }
    }

    cout << max(odd.size(), even.size()) << "\n";


    return 0;
}