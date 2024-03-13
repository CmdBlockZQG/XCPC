#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5+3;
int a[N];

void solve() {
    ll n, c;
    scanf("%lld %lld", &n, &c);
    ll ans = 0;
    ll cnt[2] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ans += c - a[i] + 1;
        if (a[i] & 1) {
            ans += (a[i] + 1) / 2;
        } else {
            ans += a[i] / 2 + 1;
        }
        cnt[a[i] & 1] += 1;
    }
    ans -= n;
    ans -= cnt[0] * (cnt[0] - 1) / 2;
    ans -= cnt[1] * (cnt[1] - 1) / 2;
    printf("%lld\n", (c + 1) * (c + 2) / 2 - ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}