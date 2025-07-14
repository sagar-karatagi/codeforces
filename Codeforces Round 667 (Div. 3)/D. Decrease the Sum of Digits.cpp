#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    int temp;
    for (int i = 0; i < n; ++i) cin >> temp; // y-values ignored

    sort(x.begin(), x.end());

    vector<int> dp(n), bestLeft(n);
    int l = 0;

    // Compute dp[i]: max number of points in platform ending at i
    for (int r = 0; r < n; ++r) {
        while (x[r] - x[l] > k) l++;
        dp[r] = r - l + 1;
    }

    // Compute prefix maximum
    bestLeft[0] = dp[0];
    for (int i = 1; i < n; ++i)
        bestLeft[i] = max(bestLeft[i - 1], dp[i]);

    // Try second platform starting at each i
    int res = 0;
    l = 0;
    for (int r = 0; r < n; ++r) {
        while (x[r] - x[l] > k) l++;
        int current = r - l + 1;
        int bestBefore = (l > 0 ? bestLeft[l - 1] : 0);
        res = max(res, current + bestBefore);
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
