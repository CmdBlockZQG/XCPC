#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, x, a[55] = {0};
	scanf("%d %d", &n, &x);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ans = max(ans, a[i] - a[i - 1]);
	}
	ans = max(ans, 2 * (x - a[n]));
	printf("%d\n", ans);
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}