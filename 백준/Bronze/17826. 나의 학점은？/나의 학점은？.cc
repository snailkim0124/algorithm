#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> v;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 50; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    cin >> n;

    int rank = find(v.begin(), v.end(), n) - v.begin() + 1;

    if (rank <= 5) cout << "A+";
    else if (rank <= 15) cout << "A0";
    else if (rank <= 30) cout << "B+";
    else if (rank <= 35) cout << "B0";
    else if (rank <= 45) cout << "C+";
    else if (rank <= 48) cout << "C0";
    else if (rank <= 50) cout << "F";

    return 0;
}