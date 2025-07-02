#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        vector<int> a(n), diff(n + 2, 0), ans(n + 1, 0);

        for (int& x : a) {
            cin >> x;
            freq[x]++;
        }

        for (int i = 0; i <= n; i++) {
            int k = freq[i];
            diff[k]++;
            diff[n - i + 1]--;
            if (!k) break; 
        }

        for (int i = 0; i <= n; i++) {
            ans[i] = (i ? ans[i - 1] : 0) + diff[i];
            cout << ans[i] << (i != n ? ' ' : '\n');
        }
    }
}
