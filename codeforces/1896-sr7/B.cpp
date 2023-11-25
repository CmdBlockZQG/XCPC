#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+3;

bool a[N] = {0};
void solve() {
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		a[i] = getchar() == 'A';
	}
	getchar();
	int i, ans = 0, cnt0 = 0;
	for (i = n; i >= 1;) {
		if (!a[i]) {
			++cnt0;
			--i;
			continue;
		}
		for (; a[i]; --i) {
			if (cnt0) ++ans;
		}
		if (cnt0 > 1) ans += cnt0 - 1;
		if (cnt0) cnt0 = 1;
	}
	printf("%d\n", ans);
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	// cin >> t;
	scanf("%d\n", &t);
	while (t--) {
		solve();
	}
	return 0;
}