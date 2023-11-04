#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500001] = { 0 };
ll tmp[500001] = { 0 };
ll res = 0;
ll n, k;
bool flag = false;
void merge(ll left, ll mid, ll right)
{
	ll i = left;
	ll j = mid + 1;
	ll t = left;
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
		{
			tmp[t++] = a[i++];
		}
		else
		{
			res += j - t;
			tmp[t++] = a[j++];
		}
	}
	if (i > mid) {
		while (j <= right)
		{
			tmp[t++] = a[j++];
		}
	}
	else {
		while (i <= mid)
		{
			tmp[t++] = a[i++];
		}
	}
	
	for (int k = left; k <= right; k++) {
		a[k] = tmp[k];
	}
}

void merge_sort(ll left, ll right)
{
	if (left < right)
	{
		ll mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(0, n - 1);

	cout << res;
	return 0;
}