/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
    using LL = long long;

#define MY_MAX LL(pow(2, 31) - 1)  // numeric_limits<int>::max()
#define MY_MIN LL(-MY_MAX - 1)     // numeric_limits<int>::min()

   private:
    inline bool isInRange(LL i) { return i >= MY_MIN && i <= MY_MAX; }
    inline bool isNum(char c) { return c >= '0' && c <= '9'; }

   public:
    int myAtoi(string s)
    {
        LL my_num = 0;
        int index = 0;
        bool sign = false;

        for (; index < s.length() && s[index] != ' '; index++)
            ;

        if (s[index] == '-')
            sign = true, index++;
        else if (s[index] == '+')
            index++;

        for (; index < s.size(); index++) {
            char& now_char = s[index];

            if (isNum(now_char)) {
                if (my_num == 0 && now_char == '0') continue;

                my_num *= 10;
                my_num += (now_char - '0');

                if (!isInRange(sign ? -my_num : my_num)) return sign ? MY_MIN : MY_MAX;
            }
            else
                break;
        }

        my_num = sign ? -my_num : my_num;

        return my_num;
    }
};
// @lc code=end
