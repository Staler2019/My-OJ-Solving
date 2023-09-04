/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
   public:
    bool isIncr = true;

    int findNextStrIndex(int numRows, int nowIndex){
        if (numRows == 1) return nowIndex;

        if (isIncr) {
            nowIndex++;
            if (nowIndex + 1 == numRows) isIncr = false;
            return nowIndex;
        } else {
            nowIndex--;
            if (nowIndex == 0) isIncr = true;
            return nowIndex;
        }
    }

    string convert(string s, int numRows)
    {
        string strList[numRows];
        int nowRow = 0;

        for (char& c : s) {
            strList[nowRow] += c;

            nowRow = findNextStrIndex(numRows, nowRow);
        }

        string ans = "";
        for (string& s : strList) ans += s;

        return ans;
    }
};
// @lc code=end
