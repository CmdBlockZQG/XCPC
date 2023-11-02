#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> struct STTable {
	int n;
	static const int P = 21; // 1e6 可改小
	T (*st)[P];

	inline int pow2(int x) {
		return 1 << x;
	}

	// n:数据数量 a:数据源(下标1开始)
	STTable(int n, T *a) {
		this->n = n;
		st = new T[n + 1][P];
		for (int i = 1; i <= n; ++i) {
			st[i][0] = a[i];
		}
		for (int j = 1; j <= __lg(n); ++j) {
			for (int i = 1; i <= n - pow2(j) + 1; ++i) {
				st[i][j] = max(st[i][j - 1], st[i + pow2(j - 1)][j - 1]);
			}
		}
	}

	~STTable() {
		delete[] st;
	}

	T ask(int x, int y) {
		int p = __lg(y - x + 1);
		return max(st[x][p], st[y - pow2(p) + 1][p]);
	}
};

const int N = 1e5+3;
int a[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	STTable<int> st(n, a);
	int x, y;
	while (m--) {
		scanf("%d %d", &x, &y);
		printf("%d\n", st.ask(x, y));
	}
	return 0;
}