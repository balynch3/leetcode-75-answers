// Max Number of K-Sum Pairs
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // We store the number of times we encounter each number in a map.
        std::map<int, int> occurrences;
        for (int i = 0; i < nums.size(); i++) {
            if (occurrences.count(nums[i])) {
                occurrences[nums[i]]++;
            } else {
                occurrences[nums[i]] = 1;
            }
        }
        // Then we will loop over our map to see how many times n and k-n occur.
        // The min of n and k-n's occurrences is the number of pairs for those numbers.
        // We have a case for k/2 for even k too, as that one is paired with itself.
        int operations = 0;
        // For iterating the map's keys https://stackoverflow.com/questions/1443793/iterate-keys-in-a-c-map  
        for (const auto &pair : occurrences) {
            int key = pair.first;
            // n/2 case when k is even
            if (!(k%2) && key == k/2) {
                operations += occurrences[key]/2;
            } else if (occurrences.count(k-key) && occurrences[k-key] != 0) {
                operations += min(occurrences[key], occurrences[k-key]);
                // To prevent repetition in the loop
                occurrences[key] = 0;
                occurrences[k-key] = 0;
            }
        }
        return operations;
    }
};