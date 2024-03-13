#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;


using ll = long long;

void solve() {
    int n;
    ll l;
    scanf("%d %lld", &n, &l);
    vector<pair<ll, ll>> a(n);
    // x:差 y:固定
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a[i].y, &a[i].x);
        if (a[i].y <= l) ans = 1;
    }
    if (ans == 0) {
        printf("0\n");
        return;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        priority_queue<ll> pq;
        ll tot = 0;
        for (int j = i; j < n; ++j) {
            ll xl = l - (a[j].x - a[i].x);
            if (xl < 0) break;
            pq.push(a[j].y);
            tot += a[j].y;
            while (!pq.empty() && tot > xl) {
                tot -= pq.top();
                pq.pop();
            }
            ans = max(ans, (int)pq.size());
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}