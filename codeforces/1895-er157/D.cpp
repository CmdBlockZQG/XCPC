#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+5;
int a[N] = {0};
int cnt[32][2] = {0};

int main() {
	int n;
	scanf("%d", &n);
	int b = __lg(n);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
		for (int j = 0; j <= b; ++j) {
			++cnt[j][(a[i] >> j) & 1];
		}
	}
	for (int j = 0; j <= b; ++j) {
		++cnt[j][0];
	}

	int t = 0;

	for (int i = 0; i <= b; ++i) {
		if (n % (1 << (i + 1))) t |= (cnt[i][1] > cnt[i][0]) << i;
	}
	
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i] ^ t);
	}

	return 0;
}