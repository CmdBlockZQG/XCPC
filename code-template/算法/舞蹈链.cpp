#include <bits/stdc++.h>
using namespace std;

struct DLX {
    int n, sz; // 任务数(列数)
    int *s; // 每一列节点数 需初始化为0
    int *row, *col;
    int *L, *R, *U, *D;

    int ansd, *ans;

    // n:任务数(列数) m:决策数(行数)
    DLX(int n, int m) {
        const int max_node = n * m + n + 1; // 最多节点数
        s = new int[n + 1 + 5](); // 初始化为0
        col = new int[max_node + 5];
        row = new int[max_node + 5];
        L = new int[max_node + 5];
        R = new int[max_node + 5];
        U = new int[max_node + 5];
        D = new int[max_node + 5];
        ans = new int[m + 5];

        this->n = n;
        for (int i = 0; i <= n; ++i) {
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        L[0] = n;
        R[n] = 0;

        sz = n + 1;
    }

    ~DLX() {
        delete[] s;
        delete[] row;
        delete[] col;
        delete[] U;
        delete[] D;
        delete[] L;
        delete[] R;
        delete[] ans;
    }

    // 添加决策(行)
    // r:决策(行)编号 cols:可达成任务(列)编号
    // 均从1开始
    void addRow(int r, vector<int> &cols) {
        int t = sz;
        for (int &c : cols) {
            L[sz] = sz - 1;
            R[sz] = sz + 1;
            D[sz] = c;
            U[sz] = U[c];

            D[U[c]] = sz;
            U[c] = sz;

            row[sz] = r;
            col[sz] = c;

            ++s[c];
            ++sz;
        }
        R[sz - 1] = t;
        L[t] = sz - 1;
    }

    void remove(int c) {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i]) {
            for (int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --s[col[j]];
            }
        }
    }

    void restore(int c) {
        for (int i = U[c]; i != c; i = U[i]) {
            for (int j = L[i]; j != i; j = L[j]) {
                ++s[col[j]];
                D[U[j]] = U[D[j]] = j;
            }
        }
        L[R[c]] = R[L[c]] = c;
    }

    // 求解 返回值表示是否有解
    // 答案需要的操作数在ansd中，编号在ans中(下标0开始)
    bool dance(int d = 0) {
        if (R[0] == 0) {
            ansd = d;
            return true;
        }

        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i]) {
            if (s[i] < s[c]) c = i;
        }

        remove(c);
        for (int i = D[c]; i != c; i = D[i]) {
            ans[d] = row[i];
            for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
            if (dance(d + 1)) return true;
            for (int j = L[i]; j != i; j = L[j]) restore(col[j]);
        }
        restore(c);

        return false;
    }
};

int main() {
    int n, m, t;
    scanf("%d %d", &n, &m);
    DLX dlx(m, n);

    for (int i = 1; i <= n; ++i) {
        vector<int> cols;
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &t);
            if(t) cols.push_back(j);
        }
        dlx.addRow(i, cols);
    }

    if (!dlx.dance()) printf("No Solution!");
    else {
        for (int i = 0; i < dlx.ansd; ++i) {
            printf("%d ", dlx.ans[i]);
        }
    }
    return 0;
}