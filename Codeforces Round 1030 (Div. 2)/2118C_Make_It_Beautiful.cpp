/*
 * ---------------------------------------------------------------------------
 * Author      : Sagar Karatagi
 * GitHub      : https://github.com/sagar-karatagi
 * Problem     : Codeforces 2118C - Make It Beautiful
 * Submission  : Accepted (77 ms / 52 KB)
 * Language    : C++23 (GCC 14-64, msys2)
 * Verdict     : Accepted
 * Date        : 2025-06-27 20:11:32
 * ---------------------------------------------------------------------------
 *
 * Problem Summary:
 *   - You're given an array of integers.
 *   - You can perform at most k operations, where each operation increases any element by 1.
 *   - The "beauty" of a number is the number of 1s in its binary representation.
 *   - The goal is to maximize the total beauty of the array after at most k operations.
 *
 * Approach:
 *   - Count the number of unset bits at each bit position across all numbers.
 *   - From lowest to highest bit, flip as many unset bits as allowed by the remaining k.
 *   - Each flip increases beauty by 1 and costs 2^b (where b is the bit position).
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        long long k;
        cin >> n >> k;

        long long unsetBitCount[64] = {0}; // Counts of numbers missing bit b
        int beauty = 0;

        for (int i = 0; i < n; i++) {
            long long temp;
            cin >> temp;

            // Add the initial beauty (number of set bits in each number)
            beauty += __builtin_popcountll(temp);

            // Track which bits are unset in this number
            for (int b = 0; b < 61; b++) {
                if ((temp & (1LL << b)) == 0) {
                    unsetBitCount[b]++;
                }
            }
        }

        // Try flipping bits from lowest (cheapest) to highest
        for (int b = 0; b < 63; b++) {
            long long cost = (1LL << b);
            long long maxFlips = k / cost;
            long long flips = min(unsetBitCount[b], maxFlips);

            beauty += flips;
            k -= flips * cost;
        }

        cout << beauty << '\n';
    }

    return 0;
}
