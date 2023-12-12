/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        unsigned int currMaxArea = 0;
        int start = 0;
        int end = height.size() - 1;

        while(start < end){
            int& startHeight = height[start];
            int& endHeight = height[end];
            unsigned int tmpArea = min(startHeight, endHeight) * (end - start);
            currMaxArea = max(currMaxArea, tmpArea);

            if (startHeight < endHeight)
                start++;
            else
                end--;
        }

        return currMaxArea;
    }
};
// @lc code=end

