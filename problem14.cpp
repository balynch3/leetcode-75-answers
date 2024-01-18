// Maximum Average Subarray I
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        int largestSum = windowSum;
        for (int i = k; i < nums.size(); i++) {
            windowSum -= nums[i-k];
            windowSum += nums[i];
            largestSum = max(largestSum, windowSum);
        }
        return (double) largestSum/k;
    }
};