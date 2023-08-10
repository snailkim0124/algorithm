#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int a[15];
int ans[6];

void combi(int start, int depth) {
    if (depth == 6) {
        for (int i : ans) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < n; i++) {
        ans[depth] = a[i];
        combi(i + 1, depth + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        combi(0, 0);
        cout << "\n";
    }
    return 0;
}
