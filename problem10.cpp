// Move Zeroes
class Solution {
public:

    // This approach uses a read and write index to rewrite all the non-zero elements at the
    // beginning of the vector. After this, it writes zeroes to the remaining area.
    void moveZeroes(vector<int>& nums) {
        // Index where we rewrite the non-zero numbers to. Increments upon each non-zero
        // read.
        int writeIndex = 0;

        // We go through and write each non-zero number at the beginning of the vector
        // after the last written number, overwriting the old contents.
        for (int readIndex = 0; readIndex < nums.size(); readIndex++) {
            if (nums[readIndex] != 0) {
                // Write the current non-zero number to the write index (skip if its the same location)
                if (readIndex != writeIndex) {
                    nums[writeIndex] = nums[readIndex];
                }
                writeIndex++;
            }
        }

        // Readd zeroes to the remaining part of the vector
        for (int zeroIndex = writeIndex; zeroIndex < nums.size(); zeroIndex++) {
            nums[zeroIndex] = 0;
        }
    }
};