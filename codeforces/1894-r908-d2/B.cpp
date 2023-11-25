#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, a[105];
	map<int, int> ma;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++ma[a[i]];
	}
	if (ma.size() < 2) {
		printf("-1\n");
		return;
	}
	int x = 0, y = 0;
	for (auto &[a, b] : ma) {
		if (b >= 2) {
			if (!x) x = a;
			else y = a;
		}
	}
	if (!y) {
		printf("-1\n");
		return;
	}
	for (int i = 0; i < n; ++i) {
		int res = 1;
		if (a[i] == x) {
			res = 2;
			x = 0;
		} else if (a[i] == y) {
			res = 3;
			y = 0;
		}
		printf("%d ", res);
	}
	printf("\n");
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}