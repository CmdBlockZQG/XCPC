#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+5;

int a[N];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int l = 0, r = n - 1;
	ll ans = 0, x = 0;
	while (l < r) {
		// printf("%d %d %d %d\n", l, r, x, ans);
		if (a[l] + x > a[r]) {
			ans += a[r] - x + 1;
			a[l] = a[l] + x - a[r];
			--r;
			x = 0;
		} else if (a[l] + x == a[r]) {
			ans += a[l] + 1;
			x = 0;
			++l;
			--r;
		} else {
			x += a[l];
			ans += a[l];
			++l;
		}
	}
	// printf("%d %d %d %d\n", l, r, x, ans);
	if (l == r && a[r]) {
		int t = (x + a[r]) / 2;
		ans += t ? t - x + 1 : 0;
		ans += a[r] - t - (t - x);
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}