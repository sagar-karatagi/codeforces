/*
 * ---------------------------------------------------------------------------
 * Author      : Sagar Karatagi
 * GitHub      : https://github.com/sagar-karatagi
 * Problem     : Codeforces 2104A - Three Decks
 * Submission  : Accepted (77 ms / 100 KB)
 * Language    : C++23 (GCC 14-64, msys2)
 * Verdict     : ✅ Accepted
 * Date        : 2025-06-28 08:47 (UTC+5.5)
 * Submission  : https://codeforces.com/contest/2104/submission/326355925
 * ---------------------------------------------------------------------------
 *
 * Problem Summary:
 *   - You are given 3 integers: a, b, c.
 *   - Each represents the number of cards of a particular type.
 *   - You need to determine whether it's possible to split all cards into
 *     3 decks such that each deck has exactly the same number of cards,
 *     and no deck contains more than one card of the same type.
 *
 * Constraints:
 *   - You must split the total number of cards into 3 equal parts.
 *   - No card type can appear more than once in any deck.
 *   - Hence, each type's count must be ≤ total / 3.
 *
 * Approach:
 *   - First, check if the total sum is divisible by 3.
 *   - Then, ensure that no type count exceeds total / 3.
 */

#include <iostream>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        int total = a + b + c;

        if (total % 3 == 0 && b <= total / 3 )
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
