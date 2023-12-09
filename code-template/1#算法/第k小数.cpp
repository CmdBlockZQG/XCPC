#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// arr:元素0开始 k:0开始的排名 len:元素数量
template<typename T> T kth_ele(T arr[], int rk, int len) {
	if (len <= 1) return arr[0];
	T p = arr[rand() % len];
	int i = 0, j = 0, k = len;
	while (i < k) {
		if (arr[i] < p) swap(arr[i++], arr[j++]);
		else if (arr[i] > p) swap(arr[i], arr[--k]);
		else ++i;
	}
	if (rk < j) return kth_ele(arr, rk, j);
	else if (rk >= k) return kth_ele(arr + k, rk - k, len - k);
	else return p;
}

const int N = 5e6+3;
int a[N];

int main() {
	srand(time(0));
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d", kth_ele(a, k, n));
	return 0;
}