#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+5;
int a[N];

void solve() {
	int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int x = a[n];
    ll ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        int y = a[i];
        if (y <= x) {
            x = y;
            continue;
        }
        int p = (y + x - 1) / x;
        ans += p - 1;
        x = y / p;
    }
    printf("%lld\n", ans);
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