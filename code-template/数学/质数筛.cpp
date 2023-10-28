#include <bits/stdc++.h>
using namespace std;

struct PrimeSieve {
	int n; // 最大数范围
	int *v; // 某个数的最小质因子
	vector<int> a; // 质数
	
	PrimeSieve() {
		n = 1e8+3;
		v = new int[n]();
		init();
	}

	PrimeSieve(int t) {
		n = t + 3;
		v = new int[n]();
		init();
	}

	void init() {
		for (int i = 2; i <= n; ++i) {
			if (v[i] == 0) {
				v[i] = i;
				a.push_back(i);
			}
			for (int &p : a) {
				if (p > v[i] || p > n / i) break;
				v[i * p] = p;
			}
		}
	}

	bool is_prime(int x) {
		x = abs(x);
		if (x == 1) return false;
		return v[x] == x;
	}

	~PrimeSieve() {
		delete[] v;
	}
};

int main() {
	int n, q, r;
	scanf("%d %d", &n, &q);
	PrimeSieve prime(n);
	while (q--) {
		scanf("%d", &r);
		printf("%d\n", prime.a[r - 1]);
	}
	return 0;
}