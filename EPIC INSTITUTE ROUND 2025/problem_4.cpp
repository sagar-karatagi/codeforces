#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fillv(vec) for (auto &x : vec) cin >> x;

using ll = long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    fillv(v);

    vi a = v;
    sort(all(a));
    int threshold = (k == 1 ? INT_MIN : a[k - 2]); // Avoid out-of-bound when k = 1

    vi ans;
    for (int i = 0; i < n; i++) {
        if (v[i] <= threshold)
            ans.pb(v[i]);
    }

    int l = 0, r = sz(ans) - 1, deletedx = 0;
    bool ok = true;

    while (l < r) {
        if (ans[l] == ans[r]) {
            l++; r--;
        } else if (ans[l] == threshold) {
            l++; deletedx++;
        } else if (ans[r] == threshold) {
            r--; deletedx++;
        } else {
            ok = false;
            break;
        }
    }

    if (ok && sz(ans) - deletedx >= k - 1) yes;
    else no;
}

int main() {
    fastIO();
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
