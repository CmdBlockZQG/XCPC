#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> struct SegTree {
	int n;
	// 所有下标均从1开始
	T *a, *tree_sum, *add_tag;

	// 构造空线段树
	SegTree(int n) {
		this->n = n;
		tree_sum = new T[n * 4]();
		add_tag = new T[n * 4]();
	}

	// n:数据数量 a:数据源(下标1开始)
	SegTree(int n, T *a) {
		this->a = a;
		this->n = n;
		tree_sum = new T[n * 4]();
		add_tag = new T[n * 4]();
		build_tree();
	}

	~SegTree() {
		delete[] tree_sum;
		delete[] add_tag;
	}

	// private
	void build_tree(int x = 1, int l = 1, int r = 0) {
		r = r ? r : n;
		if (l == r) {
			tree_sum[x] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build_tree(x * 2, l, m);
		build_tree(x * 2 + 1, m + 1, r);
		tree_sum[x] = tree_sum[2 * x] + tree_sum[2 * x + 1];
	}

	// private
	void push_add_tag(int x, int l, int r, int m) {
		if (!add_tag[x] || l >= r) return;

		T t = add_tag[x];
		add_tag[x] = 0;

		int ls = 2 * x, rs = 2 * x + 1;
		tree_sum[ls] += t * (m - l + 1);
		tree_sum[rs] += t * (r - m);
		add_tag[ls] += t;
		add_tag[rs] += t;
	}

	// seg_add(l, r, k) -> [l, r] += k
	void seg_add(int l, int r, T k, int x = 1, int cl = 1, int cr = 0) {
		cr = cr ? cr : n;
		int cm = (cl + cr) / 2;
		push_add_tag(x, cl, cr, cm);
		if (cl > r || cr < l) return;
		if (l <= cl && cr <= r) {
			tree_sum[x] += k * (cr - cl + 1);
			if (cl < cr) add_tag[x] += k;
			return;
		}
		if (l <= cm) seg_add(l, r, k, 2 * x, cl, cm);
		if (r > cm) seg_add(l, r, k, 2 * x + 1, cm + 1, cr);
		tree_sum[x] = tree_sum[2 * x] + tree_sum[2 * x + 1];
	}

	// seg_sum(l, r) -> sum[l, r]
	T seg_sum(int l, int r, int x = 1, int cl = 1, int cr = 0) {
		cr = cr ? cr : n;
		int cm = (cl + cr) / 2;
		push_add_tag(x, cl, cr, cm);
		if (cl > r || cr < l) return 0;
		if (l <= cl && cr <= r) return tree_sum[x];
		T res = 0;
		if (l <= cm) res += seg_sum(l, r, 2 * x, cl, cm);
		if (r > cm) res += seg_sum(l, r, 2 * x + 1, cm + 1, cr);
		return res;
	}

};

const int N = 1e5+3;
ll a[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	SegTree<ll> tree(n, a);
	int o, x, y, k;
	while (m--) {
		scanf("%d %d %d", &o, &x, &y);
		if (o == 1) {
			scanf("%d", &k);
			tree.seg_add(x, y, k);
		} else if (o == 2) {
			printf("%lld\n", tree.seg_sum(x, y));
		}
	}
	return 0;
}