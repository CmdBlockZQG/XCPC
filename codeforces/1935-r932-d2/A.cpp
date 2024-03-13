#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        string s, t;
        cin >> s;
        t = s;
        reverse(t.begin(), t.end());
        if (t < s) {
            cout << t << s << '\n';
        } else {
            cout << s << '\n';
        }

    }
    return 0;
}