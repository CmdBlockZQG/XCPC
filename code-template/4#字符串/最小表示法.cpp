#include <bits/stdc++.h>
using namespace std;

// a:序列(下标0开始) n:序列长度
int min_representation(int a[], int n) {
	int i = 0, j = 1, k = 0;
	while (i < n && j < n && k < n) {
		if (a[(i + k) % n] == a[(j + k) % n]) ++k;
		else {
			if (a[(i + k) % n] > a[(j + k) % n]) ++i;
			else ++j;
			k = 0;
			if (i == j) ++j;
		}
	}
	return min(i, j);
}

const int N = 3e5+3;
int a[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int x = min_representation(a, n);
	for (int i = 0; i < n; ++i) printf("%d ", a[(x + i) % n]);
	return 0;
}