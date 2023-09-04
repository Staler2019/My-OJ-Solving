/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
   public:
#define INT_RANGE (pow(2, 31) - 1)

    int reverse(int x)
    {
        if (x == 0) return 0;
        // input overflow check
        if (!(x >= -INT_RANGE && x <= INT_RANGE)) return 0;

        bool signStat = (x < 0) ? true : false;
        long long ans = 0;  // overflow probability

        if (signStat) x *= -1;

        string intStack = "";
        while (x > 0) {
            intStack += ('0' + x % 10);
            x /= 10;
        }

        for (char& c : intStack) {
            ans *= 10;
            ans += (c - '0');
        }

        if (signStat) ans *= -1;

        if (!(x >= -INT_RANGE && x <= INT_RANGE)) return 0;

        return ans;
    }
};
// @lc code=end
