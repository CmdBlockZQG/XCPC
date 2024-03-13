#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int a[N];
void solve() {
    int n, x = 0;
    scanf("%d", &n);
    set<int> st;
    for (int i = 0; i <= n; ++i) {
        st.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        st.erase(a[i]);
    }
    x = *st.begin();

    // printf(">>%d\n", x);

    int count = 0;
    vector<int> l, r;

    auto init_st = [&]() -> void {
        st.clear();
        for (int i = 0; i < x; ++i) st.insert(i);
    };

    init_st();
    l.push_back(0);
    for (int i = 0; i < n; ++i) {
        st.erase(a[i]);
        if (st.size() == 0) {
            ++count;
            r.push_back(i);
            init_st();
            l.push_back(i + 1);
        }
    }
    if (count <= 1) {
        printf("-1\n");
        return;
    }
    if (l.back() == n) {
        l.pop_back();
    } else {
        l.pop_back();
        r.back() = n - 1;
    }
    printf("%d\n", count);
    for (int i = 0; i < count; ++i) {
        printf("%d %d\n", l[i] + 1, r[i] + 1);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}