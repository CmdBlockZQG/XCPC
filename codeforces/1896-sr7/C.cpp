#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+3;

int b[N], ans[N];
pair<int, int> a[N];
int solve() {
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	sort(b + 1, b + n + 1);
	
	for (int i = 1; i <= n - x; ++i) {
		if (a[i].first > b[x + i]) return 0;
		ans[a[i].second] = b[x + i];
	}
	for (int i = n - x + 1, j = 1; i <= n; ++i, ++j) {
		if (a[i].first <= b[j]) return 0;
		ans[a[i].second] = b[j];
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 1;
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		if (!solve()) {
			printf("NO\n");
		}
	}
	return 0;
}