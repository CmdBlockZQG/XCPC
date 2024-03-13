#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+3;

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
				st[i][j] = st[i][j - 1] | st[i + pow2(j - 1)][j - 1];
			}
		}
	}

	~STTable() {
		delete[] st;
	}

	T ask(int x, int y) {
		int p = __lg(y - x + 1);
		return st[x][p] | st[y - pow2(p) + 1][p];
	}
};

uint32_t x[N], y[N], w[N];

void solve() {
    int n, q;
    scanf("%d", &n);
    int bit_cnt[30][n + 1];
    memset(bit_cnt, 0, sizeof(bit_cnt));
    vector<int> bit_id[30];

    for (int i = 1; i <= n; ++i) {
        scanf("%u %u", &x[i], &y[i]);
        w[i] = 0;
        for (int j = 0; j <= 30; ++j) {
            uint32_t mask = (1 << j) - 1;
            if ((x[i] & ~mask) == (y[i] & ~mask)) {
                w[i] = x[i] & ~mask;
                x[i] &= mask;
                y[i] &= mask;
                if (j > 0) {
                    bit_cnt[j - 1][i] = 1;
                    bit_id[j - 1].push_back(i);
                }
                fflush(stdout);
                break;
            }
        }
    }
    for (int j = 0; j < 30; ++j) {
        for (int i = 1; i <= n; ++i) {
            bit_cnt[j][i] += bit_cnt[j][i - 1];
        }
    }

    STTable<uint32_t> st(n, w);
    scanf("%d", &q);
    while (q--) {
        int tmp_cnt[30] = {0};
        uint32_t tmp_num[30];
        int l, r;
        scanf("%d %d", &l, &r);
        uint32_t ans = st.ask(l, r);
        for (int i = 29; i >= 0; --i) {
            uint32_t pos = 1 << i;
            int cnt = bit_cnt[i][r] - bit_cnt[i][l - 1];
            if (ans & pos) {
                if (cnt + tmp_cnt[i] > 0) {
                    printf("%u ", ans | (pos - 1));
                    goto haha;
                }
            } else {
                if (cnt + tmp_cnt[i] > 1) {
                    printf("%u ", ans | pos | (pos - 1));
                    goto haha;
                } else if (cnt == 1) {
                    ans |= pos;
                    int id = *lower_bound(bit_id[i].begin(), bit_id[i].end(), l);
                    uint32_t tmp_next = y[id] & (pos - 1);
                    if (tmp_next != 0) {
                        int tmp_pos = __lg(tmp_next);
                        tmp_cnt[tmp_pos] += 1;
                        tmp_num[tmp_pos] = tmp_next;
                    }
                } else if (tmp_cnt[i] == 1) {
                    ans |= pos;
                    uint32_t tmp_next = tmp_num[i] & (pos - 1);
                    if (tmp_next != 0) {
                        int tmp_pos = __lg(tmp_next);
                        tmp_cnt[tmp_pos] += 1;
                        tmp_num[tmp_pos] = tmp_next;
                    }
                }
            }
        }
        printf("%u ", ans);
        haha:;
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}