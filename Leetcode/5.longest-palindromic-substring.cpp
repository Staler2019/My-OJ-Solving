/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
   public:
    bool isPali(string& s, int start, int end)
    {
        for (; end >= start; end--, start++) {
            if (s[start] != s[end]) return false;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        string substring = "";

        for (int i = 0; i < s.length(); i++) {
            for (int j = s.length() - 1; j >= i; j--) {
                // new substring.length should be (j-i+1)
                if ((j - i + 1) <= substring.length()) break;

                if (isPali(s, i, j)) substring = s.substr(i, (j - i + 1));
            }
        }

        return substring;
    }
};
// @lc code=end
