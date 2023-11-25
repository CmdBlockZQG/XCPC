#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int t = n + m - 2, s = (k - t) % 4;
    if (k < t || s & 1) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    bool a1[20][20] = {0}, a2[20][20] = {0};

    a1[2][1] = 1;
    for (int i = 1; i < m; i += 2) a1[1][i] = 1;
    for (int i = m & 1 ? 1 : 2; i < n; i += 2) a2[i][m] = 1;
    int o = a2[n - 1][m];
    a2[n - 1][m - 1] = !o;
    a1[n - 1][m - 1] = a1[n][m - 1] = o;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            printf("%c ", a1[i][j] ? 'R' : 'B');
        }
        printf("\n");
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%c ", a2[i][j] ? 'R' : 'B');
        }
        printf("\n");
    }
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