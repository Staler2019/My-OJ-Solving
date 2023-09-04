/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        while (index >= 0 && digits[index] == 9) {
            digits[index] = 0;
            index--;
        }
        if (index < 0) digits.insert(digits.begin(), 1);
        else digits[index]++;

        return digits;
    }
};
// @lc code=end

