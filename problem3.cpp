// Kids with the Greatest Number of Candies
class Solution {
public:
    bool kidWouldHaveMax(vector<int>& candies, int extraCandies, int kidIndex) {
        candies[kidIndex] += extraCandies;
        bool output = *max_element(candies.begin(), candies.end()) == candies[kidIndex];
        candies[kidIndex] -= extraCandies;
        return output;
    }

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> output(candies.size());
        for (int kid = 0; kid < output.size(); kid++) {
            output[kid] = kidWouldHaveMax(candies, extraCandies, kid);
        }
        return output;
    }
};