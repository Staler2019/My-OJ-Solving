/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
   public:
    double findNextValue(int idList[2], vector<int>& nums1,
                         vector<int>& nums2)
    {
        int& num1Id = idList[0];
        int& num2Id = idList[1];

        if (num1Id == nums1.size())
            return nums2[num2Id++];
        else if (num2Id == nums2.size())
            return nums1[num1Id++];
        else if (nums1[num1Id] >= nums2[num2Id])
            return nums2[num2Id++];
        else
            return nums1[num1Id++];
    }

    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2)
    {
        int numIds[2] = {0, 0};
        bool isNotTwoNum =
            (nums1.size() + nums2.size()) % 2;
        int targetId =
            (nums1.size() + nums2.size() - 1) / 2;
        double targetValue = 0;

        while (numIds[0] + numIds[1] <= targetId)
            targetValue =
                findNextValue(numIds, nums1, nums2);

        if (!isNotTwoNum) {
            targetValue +=
                findNextValue(numIds, nums1, nums2);
            targetValue /= 2;
        }

        return targetValue;
    }
};

// @lc code=end
