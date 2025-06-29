/* ------------------------ First Attempt (TLE in TC 5) ------------------------

This approach focuses on explicitly finding all possible valid beautiful subsequences.
The only valid pattern (since values are only 1, 2, 3) is: [1, 2, ..., 2, 3]

Key idea:
- For every 1 (at position i), and every 3 (at position j > i),
  count how many 2s exist in between (between i and j).
- For each such pair, number of valid subsequences is (2^k - 1),
  where k = number of 2s between positions i and j.
  (All non-empty subsets of 2s can go between the 1 and 3.)

Time Complexity:
- Worst case is O(n^2), if there are many 1s and 3s.

This passes small test cases but gives TLE on large ones.


#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 10;

vector<long long> pow2(MAXN);

// Precompute powers of 2 modulo MOD
void precompute_pow2() {
    pow2[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
}

// Returns sum of nCr from r=1 to r=n (i.e., 2^n - 1)
inline long long sum_nCr(int n) {
    return (pow2[n] - 1 + MOD) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute_pow2(); // Precompute all powers of 2

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<int> pre(n + 1, 0); // prefix sum of number of 2s
        vector<int> v1, v3;
        long long ans = 0;

        for (int i = 1; i <= n; ++i) {
            int temp;
            cin >> temp;
            if (temp == 1) v1.push_back(i - 1);
            else if (temp == 3) v3.push_back(i - 1);
            pre[i] = pre[i - 1] + (temp == 2);
        }

        // For each 1, find valid 3s after it and count 2s in between
        for (int &i : v1) {
            for (int j = (int)v3.size() - 1; j >= 0 && v3[j] > i && pre[v3[j]] - pre[i] > 0; --j) {
                int cnt2s = pre[v3[j]] - pre[i];
                ans = (ans + sum_nCr(cnt2s)) % MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
*/


/*
Optimized Solution (Accepted) - Based on State Transitions

This solution uses a dynamic programming approach to count subsequences
without explicitly iterating over positions. It leverages the observation
that the only valid beautiful subsequence has the pattern:
    1, 2, 2, ..., 2, 3

State Definitions:
- dp[0] = empty sequence (base case)
- dp[1] = number of subsequences ending with 1
- dp[2] = number of subsequences of form 1...2
- dp[3] = number of beautiful subsequences 1...2...3

Transitions:
- Reading a 1 → can start a new subsequence: dp[1] += dp[0]
- Reading a 2:
    - Extend existing 1...2s: dp[2] *= 2
    - Start new 1...2s from dp[1]: dp[2] += dp[1]
- Reading a 3 → complete sequences: dp[3] += dp[2]

Time Complexity: O(n) per test case.
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Fast modular addition
int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> dp(4, 0);
        dp[0] = 1;  // base case: empty sequence

        while (n--) {
            int x;
            cin >> x;

            if (x == 2) {
                // Doubling all existing sequences that already end in 2
                dp[2] = add(dp[2], dp[2]);
            }

            // Move to current state from previous
            dp[x] = add(dp[x], dp[x - 1]);
        }

        cout << dp[3] << '\n';  // Final answer: number of beautiful sequences
    }
}

