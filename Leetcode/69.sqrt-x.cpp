/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
   public:
    int mySqrt(int x)
    {
        unsigned long count = 0;
        for (int i = 1;; i++) {
            count += 2 * i - 1;
            if (count == x)
                return i;
            else if (count > x)
                return i - 1;
        }
    }
};
// @lc code=end
