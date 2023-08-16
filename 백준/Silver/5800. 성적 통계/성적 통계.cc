#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int k, n, st;
int MIN, MAX, ans;
vector<int> arr;

int main() {

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> n;
        arr.clear();
        for (int j = 0; j < n; j++) {
            cin >> st;
            arr.push_back(st);
        }
        sort(arr.begin(), arr.end());
        MIN = arr[0];
        MAX = arr[arr.size() - 1];
        ans = 0;
        for (int j = 1; j < n; j++) {
            ans = max(ans, arr[j] - arr[j - 1]);
        }
        cout << "Class " << i << "\n" << "Max " << MAX << ", Min " << MIN << ", Largest gap " << ans << "\n";
    }
}