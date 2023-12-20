// Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output (nums.size());
        // First we set it up such that each position in ans equals the product of
        // all the right elements
        // We start from the right so that the value is completely multiplied by the end
        output[nums.size()-1] = 1;
        for (int index = nums.size()-2; index >= 0; index--) {
            output[index] = output[index+1] * nums[index+1];
        }
        // Then we do the same in reverse, multiplying the current value times the left ones.
        // We start at the left so that each element to the right has all elements factored in
        int leftProduct = 1;
        for (int index = 1; index < nums.size(); index++) {
            leftProduct *= nums[index-1];
            output[index] *= leftProduct;
        }
        return output;
    }
};