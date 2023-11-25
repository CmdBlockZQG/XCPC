#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, a[205];
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + 2 * n);
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += a[i] - a[i - 1] + a[i + n] - a[i + n - 1];
	}
	printf("%d\n");
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", a[i], a[i + n]);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}