#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve() {
	int c, k, w;
	scanf("%d %d %d", &c, &k, &w);
	if (c + w >= k) {
		return max(c, k);
	} else {
		return k + (k - c - w);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%d\n", solve());
	}
	return 0;
}