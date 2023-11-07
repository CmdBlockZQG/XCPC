#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+5;

int t[N];
bool vis[N];

void solve() {
	int n, k, r;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &r);
		t[(i + 1) % n] = r > n ? -1 : (i + 1 - r + n) % n;
		vis[i] = false;
	}
	// for (int i = 0; i < n; ++i) {
	// 	printf("%d ", t[i]);
	// }
	// printf("\n");
	int cnt = 0, u = 0;
	while (true) {
		vis[u] = true;
		int &v = t[u];
		if (v == -1) break;
		if (vis[v]) {
			printf("Yes\n");
			return;
		}
		u = v;
		++cnt;
	}
	printf(cnt >= k ? "Yes\n" : "No\n");
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