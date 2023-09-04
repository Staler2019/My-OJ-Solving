/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
   public:
    string addBinary(string a, string b)
    {
        string input[2] = {a, b};
        int len[2] = {static_cast<int>(a.length()),
                      static_cast<int>(b.length())};
        bool longer =
            (b.length() > a.length());  // 0 for a, 1 for b

        vector<bool> rev_ans;
        bool carry = 0;
        for (int i = 0; i < len[!longer]; i++) {
            int sum = input[0][len[0] - 1 - i] - '0' +
                      input[1][len[1] - 1 - i] - '0' +
                      carry;
            carry = sum / 2;
            rev_ans.push_back(sum % 2);
        }
        for (int i = len[longer] - len[!longer] - 1; i >= 0;
             i--) {
            int sum = input[longer][i] - '0' + carry;
            carry = sum / 2;
            rev_ans.push_back(sum % 2);
        }

        string ans = (carry) ? "1" : "";
        for (int i = rev_ans.size() - 1; i >= 0; i--)
            ans += (char)(rev_ans[i] + '0');
        return ans;
    }
};
// @lc code=end
