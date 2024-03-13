#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+3;

void solve() {
	int n, u, v;
	scanf("%d", &n);
	
	int d[n + 1] = {0};

	for (int i = 1; i <= n - 1; ++i) {
		scanf("%d %d", &u, &v);
		++d[u];
		++d[v];
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += (d[i] == 1);
	}
	
	printf("%d\n", (cnt + 1) / 2);

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