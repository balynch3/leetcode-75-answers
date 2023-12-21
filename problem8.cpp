// Increasing Triplet Subsequence
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, middle = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            // The left value is used to create a middle value, which is then used to find
            // an answer. We change the left value if we encounter something lower in case
            // a different middle can be found. The middle can still be used as every value
            // has at least one set of valid preceding elements.
            // It doesn't matter if we overwrite a different valid sequence, as we just need
            // to find at least one valid one.
            if (left > nums[i]) {
                left = nums[i];
            } else if (middle > nums[i] && left < nums[i]) {
                middle = nums[i];
            } else if (middle < nums[i]) {
                return true;
            }
        }
        return false;
    }
};