#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int n;
int arr[200005];
int res;
unordered_map<int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;

    while (right < n) {
        cnt[arr[right]]++;

        while (cnt.size() > 2) {
            cnt[arr[left]]--;
            if (cnt[arr[left]] == 0) {
                cnt.erase(arr[left]);
            }
            left++;
        }

        res = max(res, right - left + 1);
        right++;
    }

    cout << res;

    return 0;
}
