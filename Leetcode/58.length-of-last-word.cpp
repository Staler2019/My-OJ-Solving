/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLastWord(string s)
    {
        int end = s.length() - 1;
        while (end > 0 && s[end] == ' ') end--;

        int start = end;
        while (start > -1 && s[start] != ' ') start--;

        return end - start;
    }
};
// @lc code=end
