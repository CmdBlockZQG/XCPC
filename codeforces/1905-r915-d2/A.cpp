#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", max(n, m));
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