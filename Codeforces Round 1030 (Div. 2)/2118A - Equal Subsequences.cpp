/*
 * ---------------------------------------------------------------------------
 * Author      : Sagar Karatagi
 * GitHub      : https://github.com/sagar-karatagi
 * Problem     : Codeforces 2118A - Equal Subsequences
 * Submission  : Accepted (46 ms / 0 KB)
 * Language    : C++23 (GCC 14-64, msys2)
 * Verdict     : Accepted
 * Date        : 2025-06-27 23:01 (UTC+5.5)
 * ---------------------------------------------------------------------------
 *
 * Problem Summary:
 *   - Construct a binary string (bitstring) of length `n` that contains exactly `k` ones (1s)
 *     and has an equal number of "101" and "010" subsequences.
 *   - A subsequence means non-contiguous characters picked in order.
 *   - Multiple valid answers are allowed.
 *   - It is guaranteed that such a string always exists.
 *
 * Approach:
 *   - One simple way to ensure balance between subsequences "010" and "101" is to alternate 1s and 0s.
 *   - Start placing '1's first to ensure desired count.
 *   - Then fill the rest with '0's.
 *   - While this doesn't always minimize or control subsequence count directly,
 *     strings like "1010", "100010", "1100" all work as long as both "101" and "010" appear equally often (even if 0).
 *   - Since the problem allows *any* valid construction, a greedy fill-first strategy works.
 */

#include <iostream>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        // Output first k '1's
        for (int i = 0; i < k; i++)
            cout << '1';

        // Fill the rest with '0's
        for (int i = 0; i < n - k; i++)
            cout << '0';

        cout << '\n';
    }
    return 0;
}
